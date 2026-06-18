import os
import sys
from pathlib import Path

project_root = Path(__file__).parent.parent
if str(project_root) not in sys.path:
    sys.path.insert(0, str(project_root))

from fastapi import FastAPI, HTTPException
from fastapi.staticfiles import StaticFiles
from fastapi.responses import HTMLResponse
from fastapi.middleware.cors import CORSMiddleware
from core.driver import PrinterDriver
from core.saver import PrinterStateStorage
from core.printer import Printer
from core.exceptions import (
    OutOfPaperError, LowInkError, HardwareError,
    PrinterException, InvalidDocumentError
)
from web.models import (
    PrinterStatus,
    LoadPaperRequest, ReplaceInkRequest, MaintenanceRequest, PrintRequest
)
from core.settings import PrintSettings
from core.document import Document
app = FastAPI(title="Принтер")
driver = PrinterDriver()
storage = PrinterStateStorage("web_printer_state.json")
printer: Printer = storage.load(driver)

# Настройка CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

static_dir = Path(__file__).parent / "static"
if static_dir.exists():
    app.mount("/static", StaticFiles(directory=str(static_dir)), name="static")


@app.get("/", response_class=HTMLResponse)
async def get_web_interface():
    index_file = static_dir / "index.html"
    if index_file.exists():
        with open(index_file, "r", encoding="utf-8") as f:
            return HTMLResponse(content=f.read())
    return HTMLResponse(content="<h1>Web interface files not found</h1>")


@app.get("/api/status", response_model=PrinterStatus)
async def get_printer_status():
    try:
        status = printer.get_status()
        return PrinterStatus(**status)
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/power/on")
async def power_on_printer():
    try:
        success = printer.power_on()
        storage.save(printer)
        if success:
            return {"message": "Принтер успешно включен"}
        else:
            raise HTTPException(status_code=400, detail="Не удалось включить принтер")
    except HardwareError as e:
        raise HTTPException(status_code=500, detail=str(e))
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/power/off")
async def power_off_printer():
    try:
        success = printer.power_off()
        storage.save(printer)
        if success:
            return {"message": "Принтер успешно выключен"}
        else:
            raise HTTPException(status_code=400, detail="Принтер уже выключен")
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/print")
async def print_document(request: PrintRequest):
    try:

        doc = Document(
            request.document.filename,
            request.document.format,
            request.document.pages,
            request.document.size_mb
        )

        print_settings = None
        if request.settings:
            print_settings = PrintSettings(
                quality=request.settings.quality,
                color_mode=request.settings.color_mode,
                copies=request.settings.copies,
            )

        success = printer.print_document(doc, print_settings)
        storage.save(printer)

        if success:
            return {"message": f"Документ '{request.document.filename}' успешно напечатан"}
        else:
            raise HTTPException(status_code=500, detail="Ошибка при печати")

    except InvalidDocumentError as e:
        raise HTTPException(status_code=400, detail=str(e))
    except OutOfPaperError:
        raise HTTPException(status_code=400, detail="Недостаточно бумаги")
    except LowInkError:
        raise HTTPException(status_code=400, detail="Недостаточно чернил")
    except PrinterException as e:
        raise HTTPException(status_code=400, detail=str(e))
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/paper/load")
async def load_paper(request: LoadPaperRequest):
    try:
        printer.load_paper(request.quantity)
        storage.save(printer)
        return {"message": f"Загружено {request.quantity} листов бумаги"}
    except PrinterException as e:
        raise HTTPException(status_code=400, detail=str(e))
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/ink/replace")
async def replace_ink(request: ReplaceInkRequest):
    try:
        printer.replace_ink(request.color)
        storage.save(printer)
        return {"message": f"Картридж {request.color} успешно заменен"}
    except ValueError as e:
        raise HTTPException(status_code=400, detail=str(e))
    except PrinterException as e:
        raise HTTPException(status_code=400, detail=str(e))
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.post("/api/maintenance")
async def run_maintenance(request: MaintenanceRequest):
    try:
        success = printer.start_maintenance(request.operation)
        storage.save(printer)
        if success:
            return {"message": f"Обслуживание '{request.operation}' успешно выполнено"}
        else:
            raise HTTPException(status_code=500, detail="Ошибка при выполнении обслуживания")
    except PrinterException as e:
        raise HTTPException(status_code=400, detail=str(e))
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


@app.delete("/api/reset")
async def reset_printer():
    global printer
    try:
        printer = Printer("WebPrinter", driver)
        storage.save(printer)
        return {"message": "Принтер сброшен к начальному состоянию"}
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


if __name__ == "__main__":
    import uvicorn

    host = os.getenv("HOST", "127.0.0.1")
    port = int(os.getenv("PORT", 8000))

    print(f"Запуск веб-сервера на http://{host}:{port}")

    uvicorn.run(
        "web.main:app",
        host=host,
        port=port,
        reload=True,
        log_level="info"
    )