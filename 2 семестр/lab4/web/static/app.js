class PrinterApp {
    constructor() {
        this.apiUrl = '/api';
        this.initEventListeners();
        this.updateStatus();
        // Обновлять статус каждые 5 секунд
        setInterval(() => this.updateStatus(), 5000);
    }

    initEventListeners() {
        // Управление питанием
        document.getElementById('power-on').addEventListener('click', () => this.powerOn());
        document.getElementById('power-off').addEventListener('click', () => this.powerOff());

        // Управление бумагой
        document.getElementById('load-paper').addEventListener('click', () => this.loadPaper());

        // Управление чернилами
        document.getElementById('replace-ink').addEventListener('click', () => this.replaceInk());

        // Обслуживание
        document.getElementById('run-maintenance').addEventListener('click', () => this.runMaintenance());

        // Печать
        document.getElementById('print-form').addEventListener('submit', (e) => {
            e.preventDefault();
            this.printDocument();
        });

        // Сброс
        document.getElementById('reset-printer').addEventListener('click', () => this.resetPrinter());
    }

    async makeRequest(method, endpoint, data = null) {
        const url = `${this.apiUrl}${endpoint}`;
        const options = {
            method: method,
            headers: {
                'Content-Type': 'application/json'
            }
        };

        if (data) {
            options.body = JSON.stringify(data);
        }

        try {
            const response = await fetch(url, options);
            if (!response.ok) {
                const errorData = await response.json().catch(() => ({detail: 'Unknown error'}));
                throw new Error(errorData.detail || `HTTP ${response.status}`);
            }
            return await response.json();
        } catch (error) {
            this.showMessage(`Ошибка: ${error.message}`, 'error');
            throw error;
        }
    }

    async updateStatus() {
        try {
            const status = await this.makeRequest('GET', '/status');
            this.displayStatus(status);
        } catch (error) {
            console.error('Failed to update status:', error);
        }
    }

    displayStatus(status) {
        const statusDiv = document.getElementById('printer-status');

        let html = `<strong>Модель:</strong> ${status.model}<br>`;
        html += `<strong>Состояние:</strong> <span class="state-${status.state}">${this.formatState(status.state)}</span><br>`;
        html += `<strong>Бумага:</strong> ${status.paper.type}, ${status.paper.quantity} листов<br>`;
        html += `<strong>Картриджи:</strong><br>`;

        status.cartridges.forEach(cartridge => {
            const emptyClass = cartridge.is_empty ? 'cartridge-empty' : '';
            html += `<span class="${emptyClass}">  ${cartridge.color}: ${cartridge.level_percent}% (${cartridge.level_ml}/${cartridge.capacity_ml} мл)</span><br>`;
        });

        html += `<strong>Обслуживаний:</strong> ${status.maintenance_count}`;

        statusDiv.innerHTML = html;
    }

    formatState(state) {
        const states = {
            'off': 'Выключен',
            'idle': 'Ожидание',
            'printing': 'Печать',
            'out_of_paper': 'Нет бумаги',
            'low_ink': 'Низкий уровень чернил',
            'error': 'Ошибка',
            'maintenance': 'Обслуживание'
        };
        return states[state] || state;
    }

    showMessage(message, type = 'success') {
        const messageArea = document.getElementById('message-area');
        messageArea.className = `message-${type}`;
        messageArea.textContent = message;
        setTimeout(() => {
            messageArea.textContent = '';
            messageArea.className = '';
        }, 5000);
    }

    async powerOn() {
        try {
            await this.makeRequest('POST', '/power/on');
            this.showMessage('Принтер включен');
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }

    async powerOff() {
        try {
            await this.makeRequest('POST', '/power/off');
            this.showMessage('Принтер выключен');
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }

    async loadPaper() {
        const quantity = parseInt(document.getElementById('paper-quantity').value);
        if (isNaN(quantity) || quantity <= 0) {
            this.showMessage('Введите корректное количество бумаги', 'error');
            return;
        }

        try {
            await this.makeRequest('POST', '/paper/load', {quantity});
            this.showMessage(`Загружено ${quantity} листов бумаги`);
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }

    async replaceInk() {
        const color = document.getElementById('ink-color').value;
        try {
            await this.makeRequest('POST', '/ink/replace', {color});
            this.showMessage(`Картридж ${color} заменен`);
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }

    async runMaintenance() {
        const operation = document.getElementById('maintenance-operation').value;
        try {
            await this.makeRequest('POST', '/maintenance', {operation});
            this.showMessage(`Обслуживание "${operation}" выполнено`);
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }

    async printDocument() {
        const filename = document.getElementById('filename').value;
        const format = document.getElementById('format').value;
        const pages = parseInt(document.getElementById('pages').value);
        const size = parseFloat(document.getElementById('size').value);
        const quality = document.getElementById('quality').value;
        const colorMode = document.getElementById('color-mode').value;
        const copies = parseInt(document.getElementById('copies').value);

        if (!filename || isNaN(pages) || pages <= 0 || isNaN(size) || size <= 0 || isNaN(copies) || copies <= 0) {
            this.showMessage('Заполните все поля корректно', 'error');
            return;
        }

        const documentData = {
            filename,
            format,
            pages,
            size_mb: size
        };

        const settingsData = {
            quality,
            color_mode: colorMode,
            copies
        };

        try {
            await this.makeRequest('POST', '/print', documentData, settingsData);
            this.showMessage(`Документ "${filename}" отправлен на печать`);
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }

    async resetPrinter() {
        if (!confirm('Вы уверены, что хотите сбросить принтер к начальному состоянию?')) {
            return;
        }

        try {
            await this.makeRequest('DELETE', '/reset');
            this.showMessage('Принтер сброшен к начальному состоянию');
            this.updateStatus();
        } catch (error) {
            // Ошибка уже обработана в makeRequest
        }
    }
}

// Исправление метода makeRequest для поддержки двух объектов данных
PrinterApp.prototype.makeRequest = async function(method, endpoint, documentData = null, settingsData = null) {
    const url = `${this.apiUrl}${endpoint}`;
    const options = {
        method: method,
        headers: {
            'Content-Type': 'application/json'
        }
    };

    if (documentData && settingsData) {
        // Для печати отправляем оба объекта
        options.body = JSON.stringify({
            document: documentData,
            settings: settingsData
        });
    } else if (documentData) {
        options.body = JSON.stringify(documentData);
    }

    try {
        const response = await fetch(url, options);
        if (!response.ok) {
            const errorData = await response.json().catch(() => ({detail: 'Unknown error'}));
            throw new Error(errorData.detail || `HTTP ${response.status}`);
        }
        return await response.json();
    } catch (error) {
        this.showMessage(`Ошибка: ${error.message}`, 'error');
        throw error;
    }
};

document.addEventListener('DOMContentLoaded', () => {
    new PrinterApp();
});