#include "accounting_system.hpp"
#include <sstream>

accounting_system::accounting_system(std::istream& csv) {
  using namespace std;
  unique_lock<shared_mutex> lck(mtx);
  string lineStr;
  while (getline(csv, lineStr)) {
    string cell;
    vector<string> lineVec;
    istringstream lineStream(lineStr);

    while (getline(lineStream, cell, ',')) {
      lineVec.push_back(cell);
    }

    if (lineVec.size() != 9) {
      throw "Incorrect Line Length"s;
    } else {
      sales.push_back({stoi(lineVec[0]), stoi(lineVec[1]), stoi(lineVec[2]),
                       stoi(lineVec[3]), stoi(lineVec[4]), stoi(lineVec[5]),
                       lineVec[6], lineVec[7], lineVec[8]});
    }
  }
}

// Copy constructor only copies data, not mutex
accounting_system::accounting_system(const accounting_system& other) {
  using namespace std;
  unique_lock<shared_mutex> lck(mtx);
  shared_lock<shared_mutex> other_lck(other.mtx);
  this->sales = other.sales;
}

accounting_system& accounting_system::operator=(const accounting_system& other) {
  using namespace std;
  unique_lock<shared_mutex> lck(mtx);
  shared_lock<shared_mutex> other_lck(other.mtx);

  sales = other.sales;
  return *this;
}

void accounting_system::to_csv(std::ostream& out) const {
  using namespace std;
  shared_lock<shared_mutex> lck(mtx);

  for (auto i = sales.begin(); i != sales.end(); ++i) {
    out << i->id << ',' << i->year << ',' << i->month << ',' << i->day << ','
        << i->quantity << ',' << i->unit_price_cents << ','
        << i->costomer_company_name << ',' << i->costomer_contact_name << ','
        << i->costomer_city << endl;
  }
}

  std::vector<const accounting_system::sale&> accounting_system::find_at_date(int year, int month, int day) const {
    using namespace std;
    vector<sale> results;
    for (const auto& i : sales) {
      if (i.year == year && i.month == month && i.day == day) {
        results.push_back(i);
      }
    }
  }

void accounting_system::add(const accounting_system::sale& other) {
  sales.push_back(other);
}
