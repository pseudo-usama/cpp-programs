import Data_Preprocessing
import Basic_Analysis
import Terrorism_By_Region
import Terrorism_By_Country
import Terrorism_By_City
import Most_Notorious_Groups
"""
    ! Data Preprocessing !
"""


def Globel_Terrorism_Data():
    return Data_Preprocessing.Data_Cleaning()


"""
    ! Basic Analysis !
"""


def Analysis(Terror):
    # Basic_Analysis.Basic_Data_Update(Terror)
    Basic_Analysis.Number_Of_Terrorist_Activities_Each_Year(Terror)
    Basic_Analysis.Attacking_Methods_by_Terrorists(Terror)
    Basic_Analysis.Favorite_Targets(Terror)


"""
    ! Terrorism By Region !
"""


def Region(Terror):
    Terrorism_By_Region.Number_of_Terrorist_Activites_By_Region(Terror)
    Terrorism_By_Region.Trend_in_Terrorist_Activities(Terror)
    Terrorism_By_Region.AttackType_vs_Region(Terror)


"""
    ! Terrorism By Country !
"""


def Country(Terror):
    Terrorism_By_Country.Top_Affected_Countries(Terror)
    Terrorism_By_Country.Attacks_vs_Killed(Terror)


"""
    ! Terrorism By City !
"""


def City(Terror, City_Range=10):
    Terrorism_By_City.Number_of_Terrorist_Activites_By_City(Terror, City_Range)
    Terrorism_By_City.Attacks_vs_Killed(Terror, City_Range)


"""
    * Data Cleaning * 
"""

Terror = Globel_Terrorism_Data()
Terror
"""
    * Some Basic Analysis * 
"""
Terror_Pakistan = Terror[Terror['Country'] == "Pakistan"]
Terror_Pakistan.head()
Analysis(Terror_Pakistan)

"""
    * Terrorism By Region *
"""
Terror_Since_2000 = Terror[Terror['Year'] >= 2000]
Region(Terror_Since_2000)

"""
    * Terrorism By Country *
"""

Country(Terror_Since_2000)

"""
    * Terrorism By City *
"""
City(Terror_Since_2000, 20)


Most_Notorious_Groups.Terrorist_Group(Terror_Since_2000)
Most_Notorious_Groups.Terrorist_Group_Trend(Terror_Since_2000)
