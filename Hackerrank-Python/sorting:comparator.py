from functools import cmp_to_key
class Player:
    def __init__(self, name, score):
        self.name=name
        self.score=score
        
    def __repr__(self):
        pass
        
    def comparator(a, b):
        if a.score < b.score:
            return 1
        elif a.score > b.score:
            return -1
        elif a.name > b.name:
            return 1
        elif a.name < b.name:
            return -1
        return 0
