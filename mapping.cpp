#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

struct CityRecord {
  string name;
  int population;
  double tax;
};

int main() {
  /**
   * Basically in here, we want to find the different,
   * Between vector, map, and unordered map
   * Who's faster and which one have better performance
   */

  cout << "Let's test our vector method\n" << endl;

  vector<CityRecord> cities;

  cities.push_back({"Purwokerto", 250, 2.4});
  cities.push_back({"Kebumen", 100, 2.4});
  cities.push_back({"Jogja", 350, 2.4});
  cities.push_back({"Tegal", 150, 2.4});

  for (const auto& city: cities) {
    if (city.name != "Tegal") continue;

    cout << "Current city is " << city.name << endl;
    cout << "With total population " << city.population << endl;
    cout << "And average tax ratio " << city.tax << endl;
    cout << "==========================" << endl;
  }

  cout << "\nLet's test our map method\n" << endl; 

  map<string, CityRecord> cityMap;

  cityMap["Purwokerto"] = CityRecord { "Purwokerto", 250, 2.4 };
  cityMap["Kebumen"] = CityRecord { "Kebumen", 100, 2.4 };
  cityMap["Jogja"] = CityRecord { "Jogja", 350, 2.4 };
  cityMap["Tegal"] = CityRecord { "Tegal", 150, 2.4 };

  CityRecord& dataTegal = cityMap["Tegal"];

  cout << "Current city is " << dataTegal.name << endl;
  cout << "With total population " << dataTegal.population << endl;
  cout << "And average tax ratio " << dataTegal.tax << endl;
  cout << "==========================" << endl;

  cout << "\nLet's test our map method\n" << endl; 

  unordered_map<string, CityRecord> cityUnorderMap;

  cityUnorderMap["Purwokerto"] = CityRecord { "Purwokerto", 250, 2.4 };
  cityUnorderMap["Kebumen"] = CityRecord { "Kebumen", 100, 2.4 };
  cityUnorderMap["Jogja"] = CityRecord { "Jogja", 350, 2.4 };
  cityUnorderMap["Tegal"] = CityRecord { "Tegal", 150, 2.4 };

  CityRecord& dataUnorderTegal = cityUnorderMap["Tegal"];

  cout << "Current city is " << dataUnorderTegal.name << endl;
  cout << "With total population " << dataUnorderTegal.population << endl;
  cout << "And average tax ratio " << dataUnorderTegal.tax << endl;
  cout << "==========================" << endl;

  /**
   * So we know that map is faster than vector
   * But the different between map and unordered is
   * Alpha sorted, so if you need data key sorted
   * then use map, if not then use unordered
   */

  return 0;
}

