import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    pivot_df = weather.pivot(
        index = 'month',
        columns = 'city',
        values = 'temperature'
    )
    
    return pivot_df