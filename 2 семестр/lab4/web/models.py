from pydantic import BaseModel
from typing import List, Optional
from enum import Enum

class PrinterState(str, Enum):
    OFF = "off"
    IDLE = "idle"
    PRINTING = "printing"
    OUT_OF_PAPER = "out_of_paper"
    LOW_INK = "low_ink"
    ERROR = "error"
    MAINTENANCE = "maintenance"

class DocumentCreate(BaseModel):
    filename: str
    format: str
    pages: int
    size_mb: float

class PrintSettings(BaseModel):
    quality: str = "normal"
    color_mode: str = "color"
    copies: int = 1

class PaperInfo(BaseModel):
    type: str
    quantity: int
    is_empty: bool

class CartridgeInfo(BaseModel):
    color: str
    level_percent: float
    level_ml: float
    capacity_ml: float
    is_empty: bool

class PrinterStatus(BaseModel):
    model: str
    state: PrinterState
    paper: PaperInfo
    cartridges: List[CartridgeInfo]
    maintenance_count: int

class LoadPaperRequest(BaseModel):
    quantity: int = 100

class ReplaceInkRequest(BaseModel):
    color: str

class MaintenanceRequest(BaseModel):
    operation: str = "clean"

class PrintRequest(BaseModel):
    document: DocumentCreate
    settings: Optional[PrintSettings] = None