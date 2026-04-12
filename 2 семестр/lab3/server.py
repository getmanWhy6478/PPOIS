#!/usr/bin/env python3
import sys
import os

# Добавляем текущую директорию в path
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from network import NetworkServer


def main():
    print("=" * 50)
    print("РЕВЕРСИ - ИГРОВОЙ СЕРВЕР")
    print("=" * 50)

    try:
        from config import CONFIG
        host = CONFIG.get_server_host()
        port = CONFIG.get_server_port()
        print(f"Конфигурация: host={host}, port={port}")
    except Exception as e:
        print(f"Ошибка загрузки конфигурации: {e}")
        print("Используем значения по умолчанию: 127.0.0.1:5555")
        host = "127.0.0.1"
        port = 5555

    server = NetworkServer(host=host, port=port)

    try:
        server.start()
    except KeyboardInterrupt:
        print("\nОстановка сервера...")
        server.stop()
        sys.exit(0)
    except Exception as e:
        print(f"Критическая ошибка: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()