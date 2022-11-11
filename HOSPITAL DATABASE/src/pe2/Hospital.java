package pe2;

import java.util.*;
/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU ARE SIGNING THE ABOVE STATEMENTS.

Full Name: My Nguyen
Student Number:  216861809
Course Section: 
*/

public class Hospital {
	
	private List<Physician> physicianList;
	private List<Volunteer> volunteerList;
	private List<Patient> patientList;

	

	public Hospital(Director director) {

	}

	public Object getHospDirector() {
		return null;

	}

	public boolean addAdministrator(PhysicianAdministrator Padmin) {
		// TODO Auto-generated method stub
		return false;

	}

	public boolean hirePhysician(Physician p) {
		// TODO Auto-generated method stub
		return false;
	}

}

class Person {//this should be abstract and extends hospital.
	protected String fName;
	protected String lName;
	protected int age;
	protected String gend;
	protected String add;

	public Person() {
		fName = "";
		lName = "";
	}

	public Person(String fName, String lName, int age, String gend, String add) {
		this.fName = fName;
		this.lName = lName;
		this.age = age;
		this.gend = gend;
		this.add = add;
	}

	public void setName(String fName, String lName) {
		this.fName = fName;
		this.lName = lName;
	}

	public void setAddress(String add) {
		this.add = add;
	}

	public void setGender(String gend) {
		this.gend = gend;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setFirstName(String fName) {
		this.fName = fName;
	}

	public void setLastName(String lName) {
		this.lName = lName;
	}

	public String getLastName() {
		return lName;
	}

	public String getFirstName() {
		return fName;
	}

	public Object getName() {//this should be String return type
		return (fName + ", " + lName);
	}

	public String getAddress() {
		return add;
	}

	public String getGender() {
		return gend;
	}

	public int getAge() {
		return age;
	}
//to string method is tobe defined.
	//"["+this.firstName+", " +this.lastName+", "+this.age+", "+ this.gender+", "+this.address+"]"//this is the format of the method
}

class Patient extends Person implements Comparable {
	private int pID;//patient Id is to be static 
	Physician[] a;//This has no place here
	private Physician assignedPhys;

	public Patient() { //default constructor is not necessary.

	}

	// constructor
	public Patient(String fName, String lName, int age, String gend, String add) {
		super(fName, lName, age, gend, add);
		pID++;//patient Id is incremented each time a patient is created.
	}

	@Override
	public String toString() {
		return fName + ", " + lName + ", " + age + ", " + gend + ", " + pID + ", " + add;//return "[" pID+","+super.toString()+"]"
		//refer to test 00_07_01
	}

	public void setAssignedPhysician(Physician assignedPhys) {
		this.assignedPhys = assignedPhys;

	}

	public Physician getAssignedPhysician() {
		return assignedPhys;
	}

	public Object clearPatientRecord() { //this return method is boolean
		// returns true if this.getAssignedPhysician() is null,otherwise returns false
		return null;
	}

	public void setPatientID(int pID) {
		this.pID = pID;
	}

	public int getPatientID() {
		return pID;
	}

	@Override
	public int compareTo(Object o) {
//		if(this==o)
//			return 0;
//	return this.compareTo(o) uncomment and execute.
			
		
	}

}

class Employee extends Person {//this class should be made abstract
	protected int eID;//this should be static and initialized to 99.
	protected static int nextUniqueID = 101;// this has no place

	public Employee() {//default constructor is not necessary.
		super(); // calls the Person() constructor
	}

	public int getEmployeeID() {
		return eID;
	}

	@Override
	public String toString() {
		return fName + ", " + lName + ", " + age + ", " + gend + ", " + eID + ", " + add;//returns "["Employee, +super.toString()+"]" 
		//however this is not tested.
	}
}

class Volunteer extends Employee {

	public Volunteer() {
		fName = "";
		lName = "";
		age = 0;
		gend = "";
		add = "";
	}

	// constructor
	public Volunteer(String fName, String lName, int age, String gend, String add) {
		//super constructor must be called.
		// TODO Auto-generated constructor stub
	}
//toString() method should be defined.

	//returns "["Volunteer, +super.toString+"]".
	
}

class SalariedEmployee extends Employee {//
	protected double salary;

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public double getSalary() {
		return salary;
	}

}

class Physician extends SalariedEmployee implements Comparable {
	String specialty;
	protected static int nextUniqueID = 135;//not needed.
	private List<Patient> assignedpatientList;
	private List<Volunteer> assignedVolunteerList;

	// toString()

	// constructor
	public Physician(String fName, String lName, int age, String gend, String add) {
		this.fName = fName;
		this.lName = lName;
		this.age = age;
		this.gend = gend;
		this.add = add;
		nextUniqueID++;//not needed
		eID = nextUniqueID;//not needed
	}

	public void setSpecialty(String specialty) {
		if(specialty.equals("Immunology")||specialty.equals("Dermatology")||specialty.equals("Neurology"))
		this.specialty = specialty;
		throw new IllegalArgumentException();
	}

	public String getSpecialty() {
		return specialty;
	}
	
	@Override
	public String toString() {
		return "Physician [[[" + eID + ",[" + fName + ", " + lName + ", " + age + ", " + gend + ", " + add + "]], " + salary
				+ "]]";
	}

	public boolean hasMaximumpatient() {
		return false;
	}

	public boolean hasMaxVolunteers() {
		return false;
	}

	public Physician extractPatientDetail() { // check
		return null;
	}

	public List<Patient> extractValunterDetail() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}

}

class NoSpaceException extends Exception {
	public NoSpaceException() {
	}

	public NoSpaceException(String message) {
		super(message);
	}
}

class Administrator extends SalariedEmployee {
	public Administrator(String fName, String lName, int age, String gend, String add) {
		this.fName = fName;
		this.lName = lName;
		this.age = age;
		this.gend = gend;
		this.add = add;
	}
	
	public Administrator() {
		
	}
}

class PhysicianAdministrator extends Administrator {
	String specialty;

	// constructor
	public PhysicianAdministrator(String fName, String lName, int age, String gend, String add) {
		this.fName = fName;
		this.lName = lName;
		this.age = age;
		this.gend = gend;
		this.add = add;
		nextUniqueID++;
		eID = nextUniqueID;
	}

	@Override
	public String toString() {
		return "PysicianAdministrator [[[" + eID + ",[" + fName + ", " + lName + ", " + age + ", " + gend + ", " + add + "]], " + salary
				+ "], " + specialty + "]";
	}

	/**
	 * Sets the specialty of Physician Administrator
	 * 
	 * @param specialty is the new value of specialty for each Physician
	 *                  Administrator
	 */
	public void setAdminSpecialtyType(String specialty) {
		this.specialty = specialty;
	}

	/**
	 * This method returns the specialty of Physician Administrator
	 * 
	 * @return It returns the specialty of Physician Administrator
	 */
	public String getAdminSpecialtyType() {
		return specialty;
	}

}

class Director extends Administrator {

	public Director(String fName, String lName, int age, String gend, String add) {
		super(fName, lName, age, gend, add);
	}

	@Override
	public String toString() {
		return fName + ", " + lName + ", " + age + ", " + gend + ", " + add;
	}

	public boolean assignAdministrator(PhysicianAdministrator admin1) {
		// TODO Auto-generated method stub
		return false;
	}

	public List<Patient> extractPhysicianAdmins() {
		// TODO Auto-generated method stub
		return null;
	}

}
