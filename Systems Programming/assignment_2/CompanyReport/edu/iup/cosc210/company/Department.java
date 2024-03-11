package edu.iup.cosc210.company;

/**
 * A Department of a Company.
 * 
 * @author David T. Smith
 * 
 */
public class Department {
	private String deptCode;

	private String deptName;

	private String mgrEmpId;

	private Employee[] employees = new Employee[100];

	private int noEmployees;

	private Employee manager;

	/**
	 * Constructor for Department.
	 * 
	 * @param deptCode -
	 *            the department code
	 * @param deptName -
	 *            the department name
	 * @param mgrEmpId -
	 *            the manager's employee id for the department
	 */
	public Department(String deptCode, String deptName, String mgrEmpId) {
		this.deptCode = deptCode;
		this.deptName = deptName;
		this.mgrEmpId = mgrEmpId;
	}

	/**
	 * Add an employee to the department's list of employees
	 * 
	 * @param employee -
	 *            employee to add to the department
	 */

	public void addEmployee(Employee employee) {
		employees[noEmployees++] = employee;
	}

	/**
	 * Get the code for the department
	 * 
	 * @return - the code for the department
	 */

	public String getDeptCode() {
		return deptCode;
	}

	/**
	 * Get the name of the department
	 * 
	 * @return - the name of the department
	 */

	public String getDeptName() {
		return deptName;
	}

	/**
	 * Get the manager of the department. The manager is indicated by the
	 * mgrEmpId passed on the constructor. The manager must be an employee of
	 * the department, otherwise null is returned.
	 * 
	 * @return - the department manager.
	 */
	public Employee getManager() {
		if (manager == null) {
			for (int i = 0; i < noEmployees; i++) {
				Employee emp = employees[i];
				if (emp.getEmployeeId().equals(mgrEmpId)) {
					manager = emp;
					break;
				}
			}
		}

		return manager;
	}

	/**
	 * Get the number of employees in the department
	 * 
	 * @return - the number of employees in the department
	 */
	public int getNoEmployees() {
		return noEmployees;
	}

	/**
	 * Get an employee given an index position
	 * 
	 * @param emp -
	 *            the employee to return
	 * @return - the employee at the given position
	 * @throws IndexOutOfBoundsException
	 *             if the index is less that 0 or greater than or equal to the
	 *             number of employees.
	 */
	public Employee getEmployee(int index) {
		return employees[index];
	}

	/**
	 * Get total number of vacation days of all employees in the department
	 * 
	 * @return - the total number of vacation days
	 */
	public int getTotalVacationDays() {
		int totalVacationDays = 0;
		for (int i = 0; i < noEmployees; i++) {
			Employee emp = employees[i];
			totalVacationDays += emp.getVacationDays();
		}

		return totalVacationDays;
	}
}
