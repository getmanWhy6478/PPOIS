import json
import os
from config import CONFIG


class Leaderboard:
    def __init__(self):
        self.filename = CONFIG["leaderboard_file"]
        self.scores = self.load()

    def load(self):
        if os.path.exists(self.filename):
            with open(self.filename, 'r', encoding='utf-8') as f:
                return json.load(f)
        return []

    def save(self):
        with open(self.filename, 'w', encoding='utf-8') as f:
            json.dump(self.scores, f, indent=4, ensure_ascii=False)

    def add_score(self, name, score):
        self.scores.append({"name": name, "score": score})
        self.scores.sort(key=lambda x: x["score"], reverse=True)
        self.scores = self.scores[:10]
        self.save()

    def is_high_score(self, score):
        if len(self.scores) < 10:
            return True
        return score > self.scores[-1]["score"]

    def get_top(self, n=10):
        return self.scores[:n]