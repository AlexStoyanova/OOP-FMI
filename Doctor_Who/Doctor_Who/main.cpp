#include <iostream>
#include "Date.h"
#include "Patient.h"
#include "Doctor.h"

int main()
{
	{
		Patient p1("Alex", Date(1, 5, 1998), 10);
		Patient p2("Ivan", Date(3, 3, 1999), 18);
		Patient p3("Roni", Date(17, 12, 1995), 45);
		Patient p4("Karina", Date(23, 8, 1994), 6);
		Patient p5(p2.getName(), Date(23, 8, 1994), 8);

		Doctor d1("Who");
		d1.newPatient(p1);
		d1.newPatient(p2);
		d1.newPatient(p3);
		d1.newPatient(p4);

		d1.average();
		d1.printUpper(17);
		p1.getDate().printDate();
		std::cout << p5.getName();
	}

	return 0;
}