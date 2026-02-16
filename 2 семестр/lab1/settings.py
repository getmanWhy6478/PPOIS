from dataclasses import dataclass
from typing import Literal

@dataclass
class PrintSettings:
    """Параметры печати"""
    quality: Literal['draft', 'normal', 'high'] = 'normal'
    color_mode: Literal['color', 'grayscale', 'black_and_white'] = 'color'
    paper_type: Literal['plain', 'photo', 'glossy'] = 'plain'
    copies: int = 1
    duplex: bool = False

    def __post_init__(self):
        if self.copies < 1:
            raise ValueError("Количество копий должно быть >= 1")