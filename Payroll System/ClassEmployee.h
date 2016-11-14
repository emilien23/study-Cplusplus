
#ifndef CLASSEMPLOYEE_H
#define CLASSEMPLOYEE_H
 
class Employee
{
public:
	Employee(const char *name, const char *surname);
	~Employee();
	const char *GetName() const;
	const char *GetSurname() const;
	void virtual Print() = 0;
	float virtual Earnings() = 0;
private:
	char *name;
	char *surname;
};

#endif