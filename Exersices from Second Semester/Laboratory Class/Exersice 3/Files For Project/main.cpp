#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <fstream>
#include "student.h"
using namespace std;


ostream &operator<<(ostream &,student &);
ostream &operator<<(ostream &,subject &);

void delete_help_arr(char **);
void make_help_arr(char *&, const char *);

void increase_semester(student &,student &, student &);
void decrease_semester(student &,student &, student &);
void semester_after_exams(student &,student &,student &);
void compare_students_semester(student &,student &,student &,student &,ostream &);

//Συναρτήσεις για τον κατάλογο μαθημάτων

void make_subj_array(vector<subject>&);
void process_subj_array(vector <subject>&,ostream &);





int main(void)
{ 
	int m;
	string choice;
	bool t = false;
	char* help_arr = NULL;
	unsigned int hours1 = 0,hours2 = 0,hours3 = 0;
	
	system("chcp 1253");
	cout <<"----------------------" << endl;
	
	//Δημιουργία Καταλόγου Μαθημάτων
	
	vector<subject> arr_subj;
    make_subj_array(arr_subj);
    
    cout << "ΚΑΤΑΛΟΓΟΣ ΜΑΘΗΜΑΤΩΝ" << endl;
    cout << "-----------------------------------------------------" << endl;
	
	for(int i= 0;i< arr_subj.size();i++)
	{
		cout << i+1 << ")"  << arr_subj[i];
	}
	
	
	cout << "Θα ήθελες να προσθέσεις κάποιο μάθημα που ενδέχεται να λείπει από τον κατάλογο μαθημάτων;(Ναι/Οχι)" << endl;
	cin >> choice;
	while(choice != "Οχι" && choice != "Ναι")
	{
		cout << "Επιθυμητές τιμές (Ναι ή Οχι)" << endl;
		cin >> choice;
	}
	
	while(choice == "Ναι")
	{
		t = true;
		process_subj_array(arr_subj,cout);
		cout << "Θα ήθελες να ξαναπροσθέσεις κάποιο μάθημα που ενδέχεται να λείπει από τον κατάλογο μαθημάτων;(Ναι/Οχι)" << endl;
		cin >> choice;
		while(choice != "Οχι" && choice != "Ναι")
			{
				cout << "Επιθυμητές τιμές (Ναι ή Οχι)" << endl;
				cin >> choice;
			}		
	}
	
	if(t == true)
	{
		cout<< endl << endl << endl << endl << "ΑΝΑΝΕΩΜΕΝΟΣ ΚΑΤΑΛΟΓΟΣ ΜΑΘΗΜΑΤΩΝ" << endl;
		for(int i=0;i< arr_subj.size();i++)
		{
			cout<< i << ")" << arr_subj[i];
		}
	}
	
    //Δημιουργία φοιτητών μέσω constructors, accessors και copy constructors.

	cout<< endl << endl << endl<< endl <<"ΕΑΡΙΝΟ ΕΞΑΜΗΝΟ" << endl;
	cout<<"----------------" << endl;
    cout<< "Δημιουργία Φοιτητών"<< endl;
    cout << "-------------------" << endl << endl << endl << endl;
    cout << "|-------------------------|" << endl;
    cout << "|Δημιουργία Πρώτου Φοιτητή|" << endl;
	cout << "|-------------------------|" << endl;

	//Δημιουργία Πρώτου Φοιτητή

    make_help_arr(help_arr,"22390174");

    student panagiotis(help_arr,"Πανταζόπουλος Παναγιώτης");
    cout << panagiotis;
    
    if(panagiotis.get_student_semester() > 1)
	{
		do{
			m =	panagiotis.passed_subj(arr_subj,cout);
		}while(m != 0);
	}
    
    while(1)
	{
		int subj;
		cout << "Θες να δηλώσεις κάποιο μάθημα αυτού του εξαμήνου;(Ναι/Οχι)" << endl;
		cin >> choice;
		while(choice != "Οχι" && choice != "Ναι")
		{
			cout << "Επιθυμητές τιμές (Ναι ή Οχι)" << endl;
			cin >> choice;
		}
    	if(choice == "Οχι")
		{
			break;
		}
		else
		{
			subj = panagiotis.sign_subj(arr_subj,cout);
		} 
		
		// Περίπτωση να μην θέλει να δηλώσει κανένα μάθημα

		
		if(subj == -2)
		{
			break;
		}
		
			//Εαν πήγαν όλα καλά με βάση της περιπτώσεις
		
		if(subj != -1)
		{
			panagiotis += arr_subj[subj];
			hours2 += arr_subj[subj].get_subject_hours();
		}
		if(hours2 > 38)
		{
			cout << "Δεν μπορείς να υπερβείς τις 38 ώρες" << endl;
			break;
		}
	}
	
	cout << "Καρτέλα του φοιτητή " << panagiotis.get_student_name() << endl;
	cout << panagiotis;
	
	cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|Δημιουργία Δεύτερου φοιτητή|" << endl;
	cout << "|---------------------------|" << endl;
    
    
    
    make_help_arr(help_arr,"22390052");
    
    student xarhs(help_arr,"Χάρης Σοτηρίου",2);
    cout << xarhs;
    
	if(xarhs.get_student_semester() > 1)
	{
		do{
			m =	xarhs.passed_subj(arr_subj,cout);
		}while(m != 0);
	}	
	
	
	while(1)
	{ 
		int subj;
		cout << "Θες να δηλώσεις κάποιο μάθημα αυτού του εξαμήνου;(Ναι/Οχι)" << endl;
		cin >> choice;
		while(choice != "Οχι" && choice != "Ναι")
		{
			cout << "Επιθυμητές τιμές (Ναι ή Οχι)" << endl;
			cin >> choice;
		}
    	if(choice == "Οχι")
		{
			break;
		}
		else
		{
			subj = xarhs.sign_subj(arr_subj,cout);
		} 
		
		// Περίπτωση να μην θέλει να δηλώσει κανένα μάθημα
		
		if(subj == -2)
		{
			break;
		}
		
		//Εαν πήγαν όλα καλά με βάση της περιπτώσεις
		
		if(subj != -1)
		{
			xarhs += arr_subj[subj];
			hours1 += arr_subj[subj].get_subject_hours();
		}
		if(hours1 > 38)
		{
			cout << "Δεν μπορείς να υπερβείς τις 38 ώρες" << endl;
			break;
		}	
	} 
	
	cout << "Καρτέλα του φοιτητή " << xarhs.get_student_name() << endl;
	cout << xarhs;
   
       
    //Δημιουργία Τρίτου φοιτητή.   
       
    cout<< endl<< endl << endl << "|-------------------------|" << endl;
    cout << "|Δημιουργία Τρίτου φοιτητή|" << endl;
	cout << "|-------------------------|" << endl;
	
    student nefeli = panagiotis;
    
    cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|Αρχική Μορφή Τρίτου φοιτητή|" << endl;
	cout << "|---------------------------|" << endl;
    
    cout << nefeli;
    
    make_help_arr(help_arr,"22390131");
    
    nefeli.set_student_AM(help_arr);
    delete_help_arr(&help_arr);
    nefeli.set_student_name("Νεφέλη Αργυροπούλου");
    nefeli.set_student_semester(3);
    
    cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|Τελική Μορφή Τρίτου φοιτητή|" << endl;
	cout << "|---------------------------|" << endl;
    
    cout << nefeli;
    
    if(nefeli.get_student_semester() > 1)
	{
		do{
			m = nefeli.passed_subj(arr_subj,cout);
		}while(m != 0);
	}
    
    while(1)
	{
		int subj;
		
		cout << "Θες να δηλώσεις κάποιο μάθημα αυτού του εξαμήνου;(Ναι/Οχι)" << endl;
		cin >> choice;
		while(choice != "Οχι" && choice != "Ναι")
		{
			cout << "Επιθυμητές τιμές (Ναι ή Οχι)" << endl;
			cin >> choice;
		}
    	if(choice == "Οχι")
		{
			break;
		}
		else
		{
			subj = nefeli.sign_subj(arr_subj,cout);
		} 
	
		// Περίπτωση να μην θέλει να δηλώσει κανένα μάθημα

	
		if(subj == -2)
		{
			break;
		}
		
		//Εαν πήγαν όλα καλά με βάση της περιπτώσεις

		
		if(subj != -1)
		{
			nefeli += arr_subj[subj];
			hours3 += arr_subj[subj].get_subject_hours();
		}
		if(hours3 > 38)
		{
			cout << "Δεν μπορείς να υπερβείς τις 38 ώρες" << endl;
			break;
		}
	}
	
	// Χρήση υπερφόρτωσης =
	
	cout<< endl<< endl << endl << "|---------------------------|" << endl;
    cout << "|Δημιουργία Τέταρτου φοιτητή|" << endl;
	cout << "|---------------------------|" << endl;

	
	make_help_arr(help_arr,"22390092");
	student stauros(help_arr,"Σταύρος Κάππως",3);
	stauros = nefeli;
	
	cout << stauros << endl;
	
	compare_students_semester(panagiotis,xarhs,nefeli,stauros,cout );
	
	
	
	
	//Αποθήκευση συνολικών δεδομένων σε αρχείο κειμένου
	
	ofstream outputFile;
	outputFile.open("data.txt");
	if(outputFile.is_open())
	{
		outputFile << "----------------" << endl;
		outputFile << "Καρτέλες Μαθητών" << endl;
		outputFile << "----------------" << endl;
		
		outputFile << panagiotis << endl;
		outputFile << xarhs << endl;
		outputFile << nefeli << endl;
		outputFile << stauros << endl;
		
		compare_students_semester(panagiotis,xarhs,nefeli,stauros,outputFile );	
	}
	else
	{	
		cout << "Error Opening File" << endl;
		exit(1312);
	}
	return 0;
}


//Συνάρτηση Αύξησης Εξαμήνου με τον τελεστή (+=)

void increase_semester(student &panagiotis,student &xarhs, student &nefeli)
{
    panagiotis += 1;
    xarhs += 1;
    nefeli += 1;
}

//Συνάρτηση Μείωσης Εξαμήνου (-=)

void decrease_semester(student &panagiotis,student &xarhs, student &nefeli)
{
    panagiotis -= 1;
    xarhs -= 1;
    nefeli -= 1;
}

//Συνάρτηση Αύξησης Εξαμήνου (++)

void semester_after_exams(student &panagiotis,student &xarhs,student &nefeli)
{
    panagiotis++;
    xarhs++;
    nefeli++;
}

//Αποδέσμευση βοηθητικού Πίνακα

void delete_help_arr(char **help_arr)
{
    delete [] *help_arr;
}

//Επεξεργασία βοηθητικού πίνακα

void make_help_arr(char *&help_arr,const char *AM)
{
  int len = strlen(AM);
  help_arr = new char [len + 1];
  strcpy (help_arr, AM);
}

//Δημιουργία Καταλόγου Μαθημάτων

void make_subj_array(vector<subject>& vec)
{
    int i;

    string names[] = {"Λογικές Πύλες", "Μαθηματική Ανάλυση", "Αντικειμενοστρεφής Προγραμματισμός", "C", "Λειτουργικά Συστήματα 1", "Assembly", "Δομές Δεδομένων", "Βάσεις Δεδομένων 1", "Βάσεις Δεδομένων 2",
                      "Δίκτυα", "Δίκτυα 2", "Γραμμική Άλγεβρα", "Διακριτά Μαθηματικά", "Ιστορία Της Τεχνολογίας", "Κρυπτογραφία", "Μεταγλωτιστές", "Πιθανότητες Και Στατιστική",
                      "Ρομποτική", "Σήματα Και Συστήματα","Σχεδίαση Και Ανάλυση Αλγορίθμων" , "Τεχνητή Νοημοσύνη", "Τεχνολογία Λογισμικού", "Τηλεπικοινωνιακά Συστήματα",
                      "Μεθοδολογίες Ανάπτυξης Εφαρμογών"};
    
    string password[] = {"ICE1-2005", "ICE1-1001", "ICE1-2004", "ICE1-1004", "ICE1-3005", "ICE1-3006", "ICE1-4001", "ICE1-3003", "ICE1-5001",
                         "ICE-3004", "ICE-4002", "ICE1-1002", "ICE-1005", "ICE1-740", "ICE1-7307", "ICE1-6003", "ICE-2002", "ICE1-7207", "ICE1-4006", "ICE1-2001",
                         "ICE1-5004", "CE1-6001", "ICE1-7308", "ICE1-4004"};

    int hours[] = {4, 5, 6, 6, 4, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 4, 5, 5};

    bool season[] = {true, false, true, false, false, false, true, false, false, false, true, false, false, true, true, false, true, false, true, true, false, true, true, false};
    
    
    for (i = 0; i < 24; i++)
    {
        subject subj;
        subj.set_subject_lektiko(names[i]);
        subj.set_subject_password(password[i]);
        subj.set_subject_hours(hours[i]);
        subj.set_subject_season(season[i]);
        vec.push_back(subj);
    }
}

//Περαιτέρω επεξεργασία καταλόγου μαθημάτων

void process_subj_array(vector <subject>& vec,ostream &left) 
{
	string name,password;
	unsigned int hours;
	bool season;
    
	subject k;

    left << "Δώσε όνομα μαθήματος: " << endl;
    cin >> name;

    left << "Δώσε κωδικό ονόματος: " << endl;
    cin >> password;

    left << "Δώσε ώρες διδασκαλίας του μαθήματος(0-7):" << endl;
    cin >> hours;
    
	while (k.get_subject_hours() < 0 && k.get_subject_hours() > 7) {
        left << "Λάθος τιμή:Οι ώρες διδασκαλίας κυμαίνονται μεταξύ(0-7):" << endl;
        cin >> hours;
    }

    left << "Δώσε περίοδο μαθήματος(0 = Χειμερινό, 1 = Εαρινό):" << endl;
    cin >> season;
    while(k.get_subject_season() < 0 && k.get_subject_season() > 1)
	{
		left << "Λάθος τιμή:Οι περίοοδοι του μαθημάτος μπορεί να είναι(0 = Χειμερινό Εξάμηνο ή 1 = Εαρινό Εξάμηνο)" << endl;
	}
    
    k.set_subject_hours(hours);
    k.set_subject_lektiko(name);
    k.set_subject_password(password);
    k.set_subject_season(season);

    vec.push_back(k);
} 

void compare_students_semester(student &panagiotis,student &xarhs,student &nefeli,student &stauros,ostream &left)
{
	if(stauros != nefeli)
	{
		left << "Τα εξάμηνα του " << stauros.get_student_name() << " και της " << nefeli.get_student_name() << " είναι διαφορετικά" << endl;
	}
	else
	{
		left << "Τα εξάμηνα του " << stauros.get_student_name() << " και της " << nefeli.get_student_name() << " είναι ίδια" << endl;
	}
	
	
	if(panagiotis <= xarhs)
	{
		left << "Το εξάμηνο του " << panagiotis.get_student_name() << " είναι μικρότερο ή ίσο από του " << xarhs.get_student_name() << endl;
	}
	else
	{
		left << "Το εξάμηνο του " << panagiotis.get_student_name() << " είναι μεγαλύτερο από του " << xarhs.get_student_name() << endl;
	}	
    
    
	if(xarhs == nefeli)
	{
		left << "Τα εξάμηνα του " << xarhs.get_student_name() << " και της " << nefeli.get_student_name() << " είναι ίδια" << endl;
	}
	else
	{
		left << "Τα εξάμηνα του " << xarhs.get_student_name() << " και της " <<  nefeli.get_student_name() << " είναι διαφορετικά" << endl;

	}
	
	if(panagiotis < stauros)
	{
		left << "Το εξάμηνο του " << panagiotis.get_student_name() << " είναι μικρότερο από του " << stauros.get_student_name() << endl;
	}
	else
	{
		left << "Το εξάμηνο του " << panagiotis.get_student_name() << " είναι μεγαλύτερο ή ίσο από του " << stauros.get_student_name() << endl; 	
	}
}





