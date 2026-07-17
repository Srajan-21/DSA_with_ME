import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    # return list(players.shape)
    rows , cols = players.shape
    return [rows , cols]
    