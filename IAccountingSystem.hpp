#include <string>
#include <vector>

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
};

class IAccountingSystem {
 public:
  virtual void addOrReplaceRecord(sale) = 0;
  virtual bool idExists(int id) = 0;
  virtual sale findById(int id) = 0;
  virtual std::vector<sale> findAtDate(int year, int month, int day) = 0;
  /**
   * You could have tons more methods...
   */
};