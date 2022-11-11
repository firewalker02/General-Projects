package pe2;

import static org.junit.Assert.*;

import org.junit.Test;

import noteTester.Director;
import noteTester.Hospital;
import noteTester.PhysicianAdministrator;

public class HospitalTest2 {

	@Test
	public void test_00_10_13() {

		Director director = new Director("Rebert", "Jack", 59, "Male", "Birchmount Road");
		Hospital hospital = new Hospital(director);
		PhysicianAdministrator admin1 = new PhysicianAdministrator("Elizabeth", "Smith", 53, "Female",
				"Lawrence Avenue East");
		admin1.setAdminSpecialtyType("Immunology");
		PhysicianAdministrator admin2 = new PhysicianAdministrator("Jeremy", "Dave", 45, "Male", "Guildwood Parkway");
		admin2.setAdminSpecialtyType("Dermatology");
		PhysicianAdministrator admin3 = new PhysicianAdministrator("Adam", "Tom", 55, "Male", "Danforth Road");
		admin3.setAdminSpecialtyType("Neurology");
		PhysicianAdministrator admin4 = new PhysicianAdministrator("Adamu", "Tom", 55, "Male", "Danforth Road");
		admin4.setAdminSpecialtyType("Neurology");
		hospital.addAdministrator(admin1);
		hospital.addAdministrator(admin2);
		System.out.println(hospital.addAdministrator(admin3));
		System.out.println(hospital.addAdministrator(admin4));
		System.out.println(hospital.administratorList.size());
		
		assertFalse("Test addAdministrator fail",hospital.addAdministrator(admin4) );
		
	}
	@Test
	public void test_00_10_14() {

		Director director = new Director("Rebert", "Jack", 59, "Male", "Birchmount Road");
		Hospital hospital = new Hospital(director);
		PhysicianAdministrator admin1 = new PhysicianAdministrator("Elizabeth", "Smith", 53, "Female",
				"Lawrence Avenue East");
		admin1.setAdminSpecialtyType("Immunology");
		PhysicianAdministrator admin2 = new PhysicianAdministrator("Jeremy", "Dave", 45, "Male", "Guildwood Parkway");
		admin2.setAdminSpecialtyType("Dermatology");
		PhysicianAdministrator admin3 = new PhysicianAdministrator("Adam", "Tom", 55, "Male", "Danforth Road");
		admin3.setAdminSpecialtyType("Neurology");
		PhysicianAdministrator admin4 = new PhysicianAdministrator("Adamu", "Tom", 55, "Male", "Danforth Road");
		admin4.setAdminSpecialtyType("Neurology");
		hospital.addAdministrator(admin1);
		hospital.addAdministrator(admin2);
		hospital.addAdministrator(admin3);
		hospital.addAdministrator(admin4);
		assertEquals(3,hospital.extractPhysicianAdmins().size() );
		
	}
}
