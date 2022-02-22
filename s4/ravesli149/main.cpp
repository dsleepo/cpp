#include <iostream>
#include <string>
#include <vector>

class Doctor;

class Patient {
    std::string m_name;
    std::vector<Doctor *> m_doctors;

    void addDoctor(Doctor *doctor);

public:
    Patient(std::string name): m_name(name) 
    {

    }

    friend std::ostream& operator<<(std::ostream &out, const Patient &patient);

    std::string getName() const { return m_name; }

    friend class Doctor;
};

class Doctor {
    std::string m_name;
    std::vector<Patient *> m_patients;

public:
    Doctor(std::string name): m_name(name)
    {

    }

    void addPatient(Patient *patient)
    {
        m_patients.push_back(patient);
        patient->addDoctor(this);
    }

    friend std::ostream& operator<<(std::ostream &out, const Doctor &doctor)
    {
        unsigned int length = doctor.m_patients.size();
        if (length == 0) {
            return out << doctor.m_name << " has no patients right now.";
        }

        out << doctor.m_name << " is seeing patients: ";
        for (unsigned int count = 0; count < length; ++count) {
            out << doctor.m_patients[count]->getName() << ' ';
        }

        return out;
    }

    std::string getName() const { return m_name; }
};

void Patient::addDoctor(Doctor* doctor)
{
    m_doctors.push_back(doctor);
}

std::ostream& operator<<(std::ostream &out, const Patient &patient)
{
    unsigned int length = patient.m_doctors.size();
    if (length == 0) 
    {
        out << patient.getName() << " has no doctors right now.";
        return out;
    }

    out << patient.getName() << " is seeing doctors: ";
    for (unsigned int count = 0; count < length; ++count) 
    {
        out << patient.m_doctors[count]->getName() << ' ';
    }

    return out;    
}


int main()
{
    // Создаем Пациентов вне области видимости класса Doctor
	Patient *p1 = new Patient("Anton");
	Patient *p2 = new Patient("Ivan");
	Patient *p3 = new Patient("Derek");
 
	// Создаем Докторов вне области видимости класса Patient
	Doctor *d1 = new Doctor("John");
	Doctor *d2 = new Doctor("Tom");
 
	d1->addPatient(p1);
 
	d2->addPatient(p1);
	d2->addPatient(p3);
 
	std::cout << *d1 << '\n';
	std::cout << *d2 << '\n';
	std::cout << *p1 << '\n';
	std::cout << *p2 << '\n';
	std::cout << *p3 << '\n';
 
	delete p1;
	delete p2;
	delete p3;
	
	delete d1;
	delete d2;
 
	return 0;
}