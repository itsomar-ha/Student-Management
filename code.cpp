#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>

using namespace std;

// Classes
class person {
protected:
    string fname;
    string lname;
    int age;
    string gender;
    int CoNumber;
    string mail;
    long long nationalID;
    virtual void set() = 0;
    virtual void show() = 0;
};

class students : public person {
	private: int id;
public:
    students* next;
    students* prev;
    students* headStudent;
    students* tailStudent;

    students() {
        fname = "No name";
        lname = "No name";
        age = 0;
        id = 0;
        gender = "Not Detected";
        CoNumber = 0000000000;
        mail = "No email";
        nationalID = 00000;
        next = NULL;
        prev = NULL;
        headStudent= NULL;
        tailStudent= NULL;
    }
int getNumOfStudents() {
        int count = 0;
        students* current = headStudent;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    void set() {
        char ch= ' ';
          	int i=getNumOfStudents();
        students* newStudent = new students();
        do{
        	cout<<"1. Add Student after the last\n";
        	cout<<"2. Add Student before the first\n";
        	cout<<"3. Back to the options\n";
        	cout<<"Choose from the options\n";
        	cin>>ch;
        	system("cls");
        	if(ch=='1'||ch=='2'){      
        cout << setw(72);
        cout << "---Enter The First Name : " << i+1 << "---" << ": \n";
        cin >> newStudent->fname;
        cout << setw(71);
        cout << "---Enter TheLast Name : " << i+1<< "---" << ": \n";
        cin >> newStudent->lname;
        cout << setw(72);
        cout << "---Enter ID : " << i+1 << "---" << ": \n";
        cin>>newStudent->id;
        cout << "---Enter The Age : " << i+1<< "---" << ": \n";
        cin >> newStudent->age;
        cout << setw(79);
        cout << "---Enter The Gender (Male/Female): " << i+1<< "---" << ": \n";
        cin >> newStudent->gender;
        string g=newStudent->gender;
        if(g!="male"||g!="Male"||g!="female"||g!="Female"){
        	do{
        		cout<<"Please choose (Male/Female)\n";
        		cin>>newStudent->gender;
        		g=newStudent->gender;      
        	  if(g=="male"||g=="Male"||g=="female"||g=="Female")
        	  break;	}while(g!="male"||g!="Male"||g!="female"||g!="Female");}
        cout << setw(77);
        cout << "---Enter The Contact Number : " << i+1<< "---" << ": \n";
        cin >> newStudent->CoNumber;
        cout << setw(75);
        cout << "---Enter The Email : " << i+1<< "---" << ": \n";
        cin >> newStudent->mail;
        cout << setw(73);
        cout << "---Enter The National ID : " << i+1<< "---" << ": \n";
        cin >> newStudent->nationalID;
        cout << endl;}
        	switch (ch)
        	{
        		
        		case '1':{
        
        if (headStudent == NULL) {
            headStudent = newStudent;
            tailStudent = newStudent;
        }
        else {
            tailStudent->next = newStudent;
            newStudent->prev = tailStudent;
            tailStudent = newStudent;
        }
        break;
    }
    case '2':{
        if (headStudent == NULL) {
            headStudent = newStudent;
            tailStudent = newStudent;
        }
        else {
            headStudent->prev = newStudent;
            newStudent->next = headStudent;
            headStudent = newStudent;
        }
        break;
    }
    case '3':
    cout<<"Back to the options\n";
    break;
        	}
		break;
        }while(ch!='3');
    }	
void delete_s(){
	char s=' ';
	if (headStudent==NULL)
		cout<<"there is no students to delete\n";
	else{
	   do {
        cout << "Select an option:\n";
        cout << "1. Delete the last student\n";
        cout << "2. Delete the first student\n";
        cout << "3. Delete Student by id\n";
        cout << "4. Back to options\n";
        cout << "Enter your choice\n";
        cin>>s;
        system("cls");
        switch(s){
        case '1':{
        	if(headStudent->next==NULL)
			headStudent=tailStudent=NULL;
			else{
			students* temp=tailStudent;
			tailStudent=temp->prev;
			tailStudent->next=NULL;
			free(temp);
			cout<<"Done\n";
			return;
		}
		break;
        }
		case '2':{
		if(headStudent->next==NULL)
		headStudent=tailStudent=NULL;
		else {
			students* temp=headStudent;
			headStudent=temp->next;
			headStudent->prev=NULL;
			free(temp);
			cout<<"Done\n";
			return;
		}
		break;}
		case '3':{
		int tid;
		students* temp=headStudent;
		cout<<"Enter the student id\n";
		cin>>tid;
		if (temp->id == tid){
			headStudent = temp->next;
			if (headStudent != NULL)
				headStudent->prev = NULL;
			free(temp);
			return;
		}
		while (temp != NULL && temp->id != tid){
			temp = temp->next;
		}

		if (temp == NULL){
			return;
		}
		else{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			free(temp);		
        }
		break;
        }
		case '4':
		cout<<"Back to the options\n";
		break;
		default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        break;
        }
        while(s!=4);
        }
        }	
    void show() {
           int i=1;
           if (headStudent == NULL) {
            cout << "No students found." << endl;
        }
        else {
            cout << "List of Students: " << endl;
            students* current = headStudent;
            while (current != NULL) {                   
        cout << setw(40) << i  << ". " <<current-> fname << " " << current->lname << endl;
        cout<<setw(44)<<"ID: "<<current->id<<endl;
        cout << setw(45) << "Age: " <<current-> age << endl;
        cout << setw(48) << "Gender: " << current->gender << endl;
        cout << setw(51) << "Contact Number: " << current->CoNumber << endl;
        cout << setw(48) <<"Email: " << current->mail << endl;
        cout << setw(51) << "National ID: " << current->nationalID << endl;
        cout << endl;
        current = current->next;
                i++;
    }
        }
    }
    void edit() {
           int searchID;
           bool found=false;
           if (headStudent == NULL) {
            cout << "No students added." << endl;
        }
        else {
            cout << "Enter Student ID:  " << endl;
            cin>>searchID;
            students* current = headStudent;
            while (current!=NULL) { 
            if (current->id==searchID){
              found=true;
              cout << setw(72);
        cout << "---Enter The First Name : " <<  "---" << ": \n";
        cin >> current->fname;
        cout << setw(71);
        cout << "---Enter TheLast Name : " << "---" << ": \n";
        cin >> current->lname;
        cout << setw(72);
        cout << "---Enter The Age : " << "---" << ": \n";
        cin >> current->age;
        cout << setw(79);
        cout << "---Enter The Gender (Male/Female): " <<  "---" << ": \n";        
        cin >> current->gender;
        string g=current->gender;
        if(g!="male"||g!="Male"||g!="female"||g!="Female"){
        	do{
        		cout<<"Please choose (Male/Female)\n";
        		cin>>current->gender;
        		g=current->gender;      
        	  if(g=="male"||g=="Male"||g=="female"||g=="Female")
        	  break;	}while(g!="male"||g!="Male"||g!="female"||g!="Female");}
        cout << setw(77);
        cout << "---Enter The Contact Number : " << "---" << ": \n";
        cin >> current->CoNumber;
        cout << setw(75);
        cout << "---Enter The Email : " <<  "---" << ": \n";
        cin >> current->mail;
        cout << setw(73);
        cout << "---Enter The National ID : " << "---" << ": \n";
        cin >> current->nationalID;
        cout << endl;
        break;
           }

            current=current->next;
            }
            if (found==false)
            cout<<"NOT FOUND \n";
                          }
           
        }
    void search(){
    	// s before variable for search
    	char c=' ';
        string sfname, slname;
    	int sid, sage, sconum, i=1;
    	bool done =false;
    	if(headStudent==NULL)
    	cout<<"No Students yet\n";
    	else{
    	students* search =headStudent;
        do {
        cout << "Select an option:\n";
        cout << "1. seatch by first name\n";
        cout << "2. search by last name\n";
        cout << "3. search by id\n";
        cout << "4. search by age\n";
        cout<< "5. search by contact number\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;
        system("cls");
        switch (c){
        case '1':
        cout<<"Enter The first name\n";
        cin>>sfname;
        while (search!=NULL){
        if(search->fname==sfname){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout<<setw(44)<<"ID: "<<search->id<<endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        done=true;
        }
        search = search->next;
        }
       break;
       case '2':
       cout<<"Enter The last name\n";
        cin>>slname;
        while (search!=NULL){
        if(search->lname==slname){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout<<setw(44)<<"ID: "<<search->id<<endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        done=true;
        }
        search = search->next;
        }
        break;
       case '3':
       cout<<"Enter The student id\n";
        cin>>sid;
        while (search!=NULL){
        if(search->id==sid){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout<<setw(44)<<"ID: "<<search->id<<endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        done=true;
        }
        search = search->next;
        }
        break;
       case '4':
       cout<<"Enter The Student age\n";
        cin>>sage;
        while (search!=NULL){
        if(search->age==sage){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout<<setw(44)<<"ID: "<<search->id<<endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        done=true;
        }
        search = search->next;
        }
        break;
       case '5':
      cout<<"Enter The student contact number\n";
        cin>>sconum;
        while (search!=NULL){
        if(search->CoNumber==sconum){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout<<setw(44)<<"ID: "<<search->id<<endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        done=true;
        }
        search = search->next;
        } 
       case '6':
       cout<<"Back to the main options\n";
       break;
       default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        break;
        }while (c!=6);
        if(done==false)
        cout<<"NOT FOUND\n";
    }
    }
};

class teachers : public person {
	private:
	string prof;
	float salary;
public:   
    teachers* next;
    teachers* prev;
    teachers* headTeacher;
    teachers* tailTeacher;

    teachers() {
        fname = "No name";
        lname = "No name";
        age = 0;
        prof="No Prof.";
        salary=00.00;
        gender = "Not Detected";
        CoNumber = 0000000000;
        mail = "No email";
        nationalID = 00000;
        next = NULL;
        prev = NULL;
        headTeacher = NULL;
        tailTeacher = NULL;
    }

    void set() {
        char ch=' ';
        int i=getNumOfTeachers();
        teachers* newTeacher = new teachers();
        do{
        	cout<<"1. Add teacher after the last\n";
        	cout<<"2. Add teacher before the first\n";
        	cout<<"3. Back to the options\n";
        	cout<<"Choose from the options\n";
        	cin>>ch;
        	system("cls");
        if(ch=='1'||ch=='2'){	
        cout << setw(72);
        cout << "---Enter The First Name : " << i + 1 << "---" << ": \n";
        cin >> newTeacher->fname;
        cout << setw(71);
        cout << "---Enter TheLast Name : " << i + 1 << "---" << ": \n";
        cin >> newTeacher->lname;
        cout << setw(72);
        cout << "---Enter The Age : " << i + 1 << "---" << ": \n";
        cin >>newTeacher->age;
        cout << setw(79);
        cout << "---Enter The Proffesion : " << i + 1 << "---" << ": \n";
        cin >>newTeacher->prof;
        cout << setw(79);
        cout << "---Enter The Salary : " << i + 1 << "---" << ": \n";
        cin >>newTeacher->salary;
        cout << setw(79);
        cout << "---Enter The Gender (Male/Female): " << i + 1 << "---" << ": \n";
        cin >> newTeacher->gender;
        string g=newTeacher->gender;
        if(g!="male"||g!="Male"||g!="female"||g!="Female"){
        	do{
        		cout<<"Please choose (Male/Female)\n";
        		cin>>newTeacher->gender;
        		g=newTeacher->gender;      
        	  if(g=="male"||g=="Male"||g=="female"||g=="Female")
        	  break;	}while(g!="male"||g!="Male"||g!="female"||g!="Female");}
        cout << setw(77);
        cout << "---Enter The Contact Number : " << i+ 1 << "---" << ": \n";
        cin >> newTeacher->CoNumber;
        cout << setw(75);
        cout << "---Enter The Email : " << i + 1 << "---" << ": \n";
        cin >> newTeacher->mail;
        cout << setw(73);
        cout << "---Enter The National ID : " << i + 1 << "---" << ": \n";
        cin >> newTeacher->nationalID;
        cout << endl;}
        	switch(ch){
        		case '1':{
                if (headTeacher == NULL) {
            headTeacher = newTeacher;
            tailTeacher = newTeacher;
        }
        else {
            tailTeacher->next = newTeacher;
            newTeacher->prev = tailTeacher;
            tailTeacher = newTeacher;
        }
        break;
        		}
        case '2':{
        if (headTeacher == NULL) {
            headTeacher = newTeacher;
            tailTeacher = newTeacher;
        }
        else {
            headTeacher->prev = newTeacher;
            newTeacher->next = headTeacher;
            headTeacher = newTeacher;
        }
        break;
        		}
   	case '3':
   	cout<<"Back to the options\n";
   	break;
    
        }
        break;
    }while(ch!='3');
}


    void show() {
        int i=1;
        if (headTeacher == NULL) {
            cout << "No teachers found." << endl;
        }
        else {
            cout << "List of Teachers: " << endl;
            teachers* current = headTeacher;
            while (current != NULL){
        cout << setw(40) << i  << ". " <<current->fname << " " <<current->lname << endl;
        cout << setw(45) << "Age: " << current->age << endl;
        cout << setw(45) << "Proffesion: " << current->prof << endl;
    cout << setw(45) << "Salary: " << current->salary<< endl;    
        cout << setw(48) << "Gender: " << current->gender << endl;
        cout << setw(51) << "Contact Number: " << current->CoNumber << endl;
        cout << setw(48) <<"Email: " << current->mail << endl;
        cout << setw(51) << "National ID: " << current->nationalID << endl;
        cout << endl;
        current = current->next;
                i++;
    }
        }
    }
    void delete_t(){
	char s=' ';
	if (headTeacher==NULL)
		cout<<"there is no teacher to delete\n";
	else{
	   do {
        cout << "Select an option:\n";
        cout << "1. Delete the last teacher\n";
        cout << "2. Delete the first teacher\n";
        cout << "3. Delete teqcher by national id\n";
        cout << "4. Back to options\n";
        cout << "Enter your choice\n";
        cin>>s;
        system("cls");
        switch(s){
        case '1':{
                if(headTeacher->next==NULL)
		headTeacher=tailTeacher=NULL;
		else {
			teachers* temp=tailTeacher;
			tailTeacher=temp->prev;
			tailTeacher->next=NULL;
			free(temp);
			return;
		}
		break;
        }
		case '2':{
		if(headTeacher->next==NULL)
		headTeacher=tailTeacher=NULL;
		else {
			teachers* temp=headTeacher;
			headTeacher=temp->next;
			headTeacher->prev=NULL;
			free(temp);
			return;
		}
		break;}
		case '3':{
		int tid;
		teachers* temp=headTeacher;
		cout<<"Enter the teacher national id\n";
		cin>>tid;
		if (temp->nationalID == tid){
			headTeacher = temp->next;
			if (headTeacher != NULL)
				headTeacher->prev = NULL;
			free(temp);
			return;
		}
		while (temp != NULL && temp->nationalID!= tid){
			temp = temp->next;
		}

		if (temp == NULL){
			cout<<"Not Found\n";
			return;
		}
		else{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			free(temp);		
        }
		break;
        }
		case '4':
		cout<<"Back to the options\n";
		break;
		default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        break;
        }
        while(s!=4);
        }
        }	

     int getNumOfTeachers() {
        int count = 0;
        teachers* current = headTeacher;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
    void edit() {
           long long searchNid;
           bool found=false;
           if (headTeacher == NULL) {
            cout << "No teachers added." << endl;
        }
        else {
            cout << "Enter Teacher's National ID:  " << endl;
            cin>>searchNid;
            teachers* current = headTeacher;
            while (current!=NULL) { 
            if (current->nationalID==searchNid){
              found=true;
              cout << setw(72);
        cout << "---Enter The new First Name : " <<  "---" << ": \n";
        cin >> current->fname;
        cout << setw(71);
        cout << "---Enter The new Last Name : " << "---" << ": \n";
        cin >> current->lname;
        cout << setw(72);
        cout << "---Enter The new Age : " << "---" << ": \n";
        cin >> current->age;
        cout << setw(79);
         cout << "---Enter The new Profession : " << "---" << ": \n";
        cin >> current->prof;
        cout << setw(79);
         cout << "---Enter The new Salary : " << "---" << ": \n";
        cin >> current->salary;
        cout << setw(79);
         cout << "---Enter The new Age : " << "---" << ": \n";
        cin >> current->age;
        cout << setw(79);
        cout << "---Enter The new Gender (Male/Female): " <<  "---" << ": \n";
        cin >> current->gender;
        string g=current->gender;
        if(g!="male"||g!="Male"||g!="female"||g!="Female"){
        	do{
        		cout<<"Please choose (Male/Female)\n";
        		cin>>current->gender;
        		g=current->gender;      
        	  if(g=="male"||g=="Male"||g=="female"||g=="Female")
        	  break;	}while(g!="male"||g!="Male"||g!="female"||g!="Female");}
        cout << setw(77);
        cout << "---Enter The new Contact Number : " << "---" << ": \n";
        cin >> current->CoNumber;
        cout << setw(75);
        cout << "---Enter The new Email : " <<  "---" << ": \n";
        cin >> current->mail;
        cout << setw(73);
        cout << "---Enter The new National ID : " << "---" << ": \n";
        cin >> current->nationalID;
        cout << endl;
        break;
           }

            current=current->next;
            }
            if (found==false)
            cout<<"NOT FOUND\n";
                          }
           
        }
         void search(){
    	// s before variable for search
    	char c=' ';
        string sfname, slname, sprof;
        float ssalary;
    	int sid, sage, sconum, i=1;
    	bool done=false;
    	if(headTeacher==NULL)
    	cout<<"No Teachers yet\n";
    	else{
    	teachers* search =headTeacher;
        do {
        cout << "Select an option:\n";
        cout << " 1. seatch by first name\n";
        cout << " 2. search by last name\n";
        cout << " 3. search by national id\n";
        cout << " 4. search by age\n";
        cout<< " 5. search by contact number\n";
        cout<< " 6. search by salary\n";
        cout<< " 7. search by profession\n";
        cout << " 8. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;
        system("cls");
        switch (c){
        case '1':
        cout<<"Enter The first name\n";
        cin>>sfname;
        while (search!=NULL){
        if(search->fname==sfname){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout<<setw(44)<<"National ID: "<<search->nationalID<<endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        }
       break;
       case '2':
       cout<<"Enter The last name\n";
        cin>>slname;
        while (search!=NULL){
        if(search->lname==slname){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        }
        break;
       case '3':
       cout<<"Enter The Teacher National id\n";
        cin>>sid;
        while (search!=NULL){
        if(search->nationalID==sid){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        }
        break;
       case '4':
       cout<<"Enter The teacher age\n";
        cin>>sage;
        while (search!=NULL){
        if(search->age==sage){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        }
        break;
       case '5':
      cout<<"Enter The Teacher contact number\n";
        cin>>sconum;
        while (search!=NULL){
        if(search->CoNumber==sconum){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        } 
       case '6':
             cout<<"Enter The teacher salary\n";
        cin>>ssalary;
        while (search!=NULL){
        if(search->salary==ssalary){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        } 
       case '7': 
             cout<<"Enter The Teacher profession\n";        cin>>sprof;
        while (search!=NULL){
        if(search->prof==sprof){
        cout << setw(40) << i  << ". " <<search-> fname << " " << search->lname << endl;
        cout << setw(45) << "Age: " <<search-> age << endl;
        cout << setw(48) << "Gender: " << search->gender << endl;
        cout << setw(51) << "Contact Number: " << search->CoNumber << endl;
        cout << setw(48) <<"Email: " << search->mail << endl;
        cout << setw(51) << "National ID: " << search->nationalID << endl;
        cout << endl;
        cout << setw(51) << "Profession: " << search->prof << endl;
        cout << endl;
          cout << setw(51) << "Salary:  " << search->salary << endl;
          cout<<endl;
          done=true;
        }
        search = search->next;
        } 
        case '8':
       cout<<"Back to the main options\n";
       break;
       default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        break;
        }while (c!=8);
        if (done==false)
        cout<<"NOT FOUND\n";
    }
    }
};
// Main function
int main()
{
    int choice;
    students student;
    teachers teacher;

    do {
        cout << "Select an option:\n";
        cout << "1. Add a student\n";
        cout << "2. Add a teacher\n";
        cout << "3. Show list of students\n";
        cout << "4. Show list of teachers\n";
        cout<< "5. Edit in Students\n";
        cout<< "6. Edit in Teachers \n";
        cout<< "7. Search in Students \n";
        cout<< "8. Search in Teachers \n";
        cout<< "9. Delete in Students \n";
        cout<< "10. Delete in Teachsrs\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        system("cls");
            student.set();
            system("cls");
            break;
        case 2:
        	system("cls");
            teacher.set();
            system("cls");
            break;
        case 3:
        	system("cls");
            student.show();
            cout<<endl;
            cout<<"The total number of students :-"<<student.getNumOfStudents()<<endl;
            break;
        case 4:
        	system("cls");
           teacher.show();
           cout<<endl;
           cout<<"The total number of teacher is :-"<<teacher.getNumOfTeachers()<<endl;
            break;
        case 5:
        system("cls");
        student.edit();
        system("cls");
        break;
        case 6:
        system("cls");
        teacher.edit();
        system("cls");
        break;
        case 7:
        system("cls");
        student.search();
        break;
       case 8:
       system("cls");
        teacher.search();
        break; 
        case 9:
        system("cls");
        student.delete_s();
        break; 
        case 10:
        teacher.delete_t();
        case 11:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 11);

    return 0;
}
