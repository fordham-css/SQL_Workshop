
#include <condition_variable>
#include <shared_mutex>
#include <string>
#include <vector>

class accounting_system {
 private:

  struct sale {
    int id;
    int year;
    int month;
    int day;
    int quantity;
    int unit_price_cents;
    std::string costomer_company_name;
    std::string costomer_contact_name;
    std::string costomer_city;

    // sale(int id, int year, int month, int day, int quantity,
    //      int unit_price_cents, std::string costomer_company_name,
    //      std::string costomer_contact_name, std::string costomer_city);
    // sale(const sale& other);
    // sale& operator=(const sale& other);
  };

  std::vector<sale> sales;

  // Multithreaded stuff
  mutable std::shared_mutex mtx;

 public:
  accounting_system(std::istream& csv);
  accounting_system(const accounting_system& other);
  accounting_system& operator=(const accounting_system& other);

  std::vector<const sale&> find_at_date(int year, int month, int day) const;
  std::vector<const sale&> find_from_company(std::string company) const;
  const sale& find_by_id(int id) const;

  void add(const sale& other);
  void replace(const sale& other);

  void to_csv(std::ostream& out) const;
  // And the list of methods goes on and on and on...
};