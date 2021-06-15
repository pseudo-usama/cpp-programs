import pandas as pd


def Data():
    return pd.read_csv(
        'Globel_Terrorism.csv', encoding='ISO-8859-1', low_memory=False)


"""
    ! Data Preprocessing !
"""


def Data_Cleaning():
    Dataset = Data()
    Dataset.rename(
        columns={'iyear': 'Year', 'imonth': 'Month', 'iday': 'Day', 'country_txt': 'Country',
                 'region_txt': 'Region', 'city': 'City', 'attacktype1_txt': 'AttackType', 'target1': 'Target',
                 'nkill': 'Killed', 'nwound': 'Wounded', 'summary': 'Summary', 'gname': 'Group',
                 'targtype1_txt': 'Target_type', 'weaptype1_txt': 'Weapon_type', 'motive': 'Motive'},
        inplace=True)
    Dataset = Dataset[
        ['Year', 'Month', 'Day', 'Country', 'Region',
         'City', 'latitude', 'longitude',
         'AttackType', 'Killed', 'Wounded', 'Target', 'Summary',
         'Group', 'Target_type', 'Weapon_type', 'Motive']]
    Dataset['Casualities'] = Dataset['Killed'] + \
        Dataset['Wounded']
    return Dataset
