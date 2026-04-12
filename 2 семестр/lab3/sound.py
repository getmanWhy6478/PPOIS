import pygame
import numpy as np
from config import CONFIG


class SoundManager:
    def __init__(self):
        pygame.mixer.init()
        self.sounds = {}
        self.generate_sounds()

    def generate_sounds(self):
        sample_rate = 44100

        # Звук хода
        duration = 0.1
        t = np.linspace(0, duration, int(sample_rate * duration), False)
        wave = np.sin(2 * np.pi * 440 * t) * np.exp(-10 * t)
        audio = np.int16(wave * 32767)
        stereo = np.column_stack((audio, audio))
        sound = pygame.sndarray.make_sound(stereo)
        sound.set_volume(CONFIG["sfx_volume"])
        self.sounds['move'] = sound

        # Звук победы
        duration = 0.3
        t = np.linspace(0, duration, int(sample_rate * duration), False)
        wave = np.sin(2 * np.pi * 880 * t) * np.exp(-5 * t)
        audio = np.int16(wave * 32767)
        stereo = np.column_stack((audio, audio))
        sound = pygame.sndarray.make_sound(stereo)
        sound.set_volume(CONFIG["sfx_volume"])
        self.sounds['win'] = sound

        # Звук ошибки
        duration = 0.15
        t = np.linspace(0, duration, int(sample_rate * duration), False)
        wave = np.sin(2 * np.pi * 200 * t) * np.exp(-8 * t)
        audio = np.int16(wave * 32767)
        stereo = np.column_stack((audio, audio))
        sound = pygame.sndarray.make_sound(stereo)
        sound.set_volume(CONFIG["sfx_volume"])
        self.sounds['error'] = sound

    def play_sfx(self, name):
        if name in self.sounds:
            self.sounds[name].play()

    def stop_all(self):
        pygame.mixer.stop()