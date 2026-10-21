#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    private:
        std::string firstname;
	std::string lastname;
        double gpa;
        int grad_year;
        std::string grad_sem;
        int enrolled_year;
        std::string enrolled_sem;
        std::string undergrad_grad;

    public:
        Student()
	{
	    firstname ="";
            lastname ="";
            gpa = 0.0;
            grad_year = 0;
            grad_sem = "";
            enrolled_year = 0;
            enrolled_sem = "";
	    undergrad_grad = "";
	}
	~Student(){}

	std::string getFirstname(){return firstname;}
	void setName(std::string fn, std::string ln){firstname = fn; lastname = ln;}//had to comined last and first so "art_students[]->setName("some","name");"could work
	std::string getLastname(){return lastname;}//i couldnt find a way to return both last and first name so they are seperate
	double getGPA(){return gpa;}
	void setGPA(double g){gpa=g;}
	int getGrady(){return grad_year;}
	void setGrady(int gy){grad_year = gy;}
	std::string getGrads(){return grad_sem;}
	void setGrads(std::string gs){grad_sem = gs;}
	int getEnrolly(){return enrolled_year;}
	void setEnrolly(int ey){enrolled_year = ey;}
	std::string getEnrolls(){return enrolled_sem;}
	void setEnrolls(std::string es){enrolled_sem = es;}
	std::string getUG(){return undergrad_grad;}
	void setUG(std::string ug){undergrad_grad = ug;}


    
};

class Art_Student : public Student
{
    private:
        std::string art_emphasis;
    public:
	Art_Student()
	{
	    art_emphasis = "";
	}
	~Art_Student(){}

	std::string getAE(){return art_emphasis;}
	void setAE(std::string ae){art_emphasis = ae;}
};

class Physics_Student : public Student
{
    private:
        std::string concentration;
    public:
        Physics_Student()
	{
	    concentration = "";
	}
	~Physics_Student(){}

	std::string getC(){return concentration;}
	void setC(std::string c){concentration = c;}
};

int main()
{
    std::vector<Art_Student *> art_students;
    std::vector<Physics_Student *> physics_students;
    for(int i = 0; i < 5; i++)
    {
	art_students.push_back(new Art_Student);
        art_students[i]->setGPA(0.3+i);//inside the loop because it takes less time then wtiting them out
        art_students[i]->setGrady(2030+i);
        art_students[i]->setGrads("spring");
        art_students[i]->setEnrolly(2026+i);
        art_students[i]->setEnrolls("fall");
	art_students[i]->setUG("undergrad");
    }
    art_students[0]->setName("some","name");//i didnt know how to change the names using the loop so i took them out
    art_students[1]->setName("michael","jordan");
    art_students[2]->setName("michael","jackson");
    art_students[3]->setName("mary","jane");
    art_students[4]->setName("michael","b joradan");
    art_students[0]->setAE("Art History");
    art_students[1]->setAE("Art Studio");
    art_students[2]->setAE("Art Education");
    art_students[3]->setAE("Art History");
    art_students[4]->setAE("Art Studio");

    for(int i = 0; i < 5; i++)
    {
	physics_students.push_back(new Physics_Student);
        physics_students[i]->setGPA(0.3+i);
        physics_students[i]->setGrady(2030+i);
        physics_students[i]->setGrads("spring");
        physics_students[i]->setEnrolly(2026+i);
        physics_students[i]->setEnrolls("fall");
	physics_students[i]->setUG("grad");
    }
    physics_students[0]->setName("vicente","fernandez");
    physics_students[1]->setName("juan","Gabriel");
    physics_students[2]->setName("Ludovico","peluche");
    physics_students[3]->setName("memo","ochoa");
    physics_students[4]->setName("danny","trejo");
    physics_students[0]->setC("Biophysics");
    physics_students[1]->setC("Earth and Planetary Sciences");
    physics_students[2]->setC("Biophysics");
    physics_students[3]->setC("Earth and Planetary Sciences");
    physics_students[4]->setC("Biophysics");

    //outfile = open("student_info.dat",std::ios::write); i couldn't find a way to use this in the lesson slides and has error write not part of std::ios
    std::ofstream ofile;//im using this from the lesson 2 slides, slides 40 & 41
    ofile.open("student_info.dat",std::ios::out);
    if(ofile.is_open())
    {
        for(int i = 0;i < art_students.size();i++)
        {
            ofile << "name" << art_students[i]->getFirstname()<<""<<art_students[i]->getLastname()<<"\n";
	    ofile << "GPA" << art_students[i]->getGPA()<<"\n"; 
	    ofile << "graduation year"<<art_students[i]->getGrady()<<"\n";
	    ofile << "graduation semester"<<art_students[i]->getGrads()<<"\n";
	    ofile << "enrolled year"<<art_students[i]->getEnrolly()<<"\n";
	    ofile << "enrolled semester"<<art_students[i]->getEnrolls()<<"\n";
	    ofile << "undergrad/grad"<<art_students[i]->getUG()<<"\n";
	    ofile << "art emphasis"<<art_students[i]->getAE();
        }
	for(int i = 0;i < physics_students.size();i++)
	{
            ofile << "name" << physics_students[i]->getFirstname()<<""<<physics_students[i]->getLastname()<<"\n";
            ofile << "GPA" << physics_students[i]->getGPA()<<"\n";
            ofile << "graduation year"<<physics_students[i]->getGrady()<<"\n";
            ofile << "graduation semester"<<physics_students[i]->getGrads()<<"\n";
            ofile << "enrolled year"<<physics_students[i]->getEnrolly()<<"\n";
            ofile << "enrolled semester"<<physics_students[i]->getEnrolls()<<"\n";
            ofile << "undergrad/grad"<<physics_students[i]->getUG()<<"\n";
	    ofile << "concentration" <<physics_students[i]->getC();
	}
	ofile.close();
    }

    return 0;
}

