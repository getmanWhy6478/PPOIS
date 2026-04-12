import json
import os

DEFAULT_CONFIG = {
    "window_width": 800,
    "window_height": 600,
    "board_size": 8,
    "cell_size": 60,
    "colors": {
        "background": [30, 30, 30],
        "board": [50, 150, 50],
        "board_border": [20, 100, 20],
        "black_piece": [20, 20, 20],
        "white_piece": [240, 240, 240],
        "text": [255, 255, 255],
        "highlight": [100, 255, 100]
    },
    "fps": 60,
    "music_volume": 0.3,
    "sfx_volume": 0.5,
    "leaderboard_file": "leaderboard.json",
    "server": {
        "host": "127.0.0.1",
        "port": 5555
    }
}


class Config:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance.config = cls._instance.load_config()
        return cls._instance

    def load_config(self):
        if not os.path.exists("config.json"):
            with open("config.json", "w", encoding="utf-8") as f:
                json.dump(DEFAULT_CONFIG, f, indent=4, ensure_ascii=False)
            print("Создан файл config.json")

        with open("config.json", "r", encoding="utf-8") as f:
            return json.load(f)

    def get(self, key, default=None):
        """Получение значения по ключу с поддержкой вложенности (точка)"""
        keys = key.split(".")
        value = self.config
        for k in keys:
            if isinstance(value, dict) and k in value:
                value = value[k]
            else:
                return default
        return value

    def __getitem__(self, key):
        return self.get(key)

    def get_server_host(self):
        """Специальный метод для хоста сервера"""
        try:
            host = self.get("server.host", "127.0.0.1")
            return host if host else "127.0.0.1"
        except:
            return "127.0.0.1"

    def get_server_port(self):
        """Специальный метод для порта сервера"""
        try:
            port = self.get("server.port", 5555)
            return port if port else 5555
        except:
            return 5555


CONFIG = Config()