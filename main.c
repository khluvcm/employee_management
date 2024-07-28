#include <stdio.h>

struct employee_info {
	char name[20];
	int age;
	int gender;
	int salary;
	int level;
};

void inputEmployeeInfo (struct employee_info emp[], int num_emp) {
	printf("Please Input Employee Info\n");
	printf("name: ");
	scanf("%s", emp[num_emp].name);
	printf("age: ");
	scanf("%d",&emp[num_emp].age);
	printf("level: ");
	scanf("%d",&emp[num_emp].level);
	printf("salary: ");
	scanf("%d",&emp[num_emp].salary);
	printf("(1) Mail\n");
	printf("(2) Femail\n");
	printf("gender: ");
	scanf("%d",&emp[num_emp].gender);
}

void printEmployeeInfo (struct employee_info emp[], int num_emp, int emp_id) {

	if (emp_id == 0) {
		printf("\nWe Have %d Employee Info\n", num_emp);
		printf("---------------------------\n");
		int i;
		for (i = 0; i < num_emp; i++) {
			printf("%d-th Employee\n", i+1);
			printf("  name : %s\n",emp[i].name);
			printf("  age : %d\n",emp[i].age);
			printf("  salary : %d\n",emp[i].salary);
			printf("  level : %d\n",emp[i].level);

			if (emp[i].gender == 1) {
				printf("  gender : Mail\n");
			} else if (emp[i].gender == 2) {
				printf("  gender : Femail\n");
			} else {
				printf("  gender : none\n");
			}
		}
	} else if (emp_id <= num_emp) {
		printf("%d-th Employee\n", emp_id);
		printf("  name : %s\n",emp[emp_id-1].name);
		printf("  age : %d\n",emp[emp_id-1].age);
		printf("  salary : %d\n",emp[emp_id-1].salary);
		printf("  level : %d\n",emp[emp_id-1].level);

		if (emp[emp_id -1].gender == 1) {
			printf("  gender : Mail\n");
		} else if (emp[emp_id -1].gender == 2) {
			printf("  gender : Femail\n");
		} else {
			printf("  gender : none\n");
		}

	} else {
		printf("Unrecognized Employee ID\n");
	}

}

int main () {
	struct employee_info emp[100];
	int num_emp = 0;

	int menu;

	printf("================================\n");
	printf("  Employee Management Program \n");
	printf("================================\n");

	while (1) {
		printf("================================\n");
		printf("(1) Input new employee\n");
		printf("(2) Print employee info\n");
		printf("(3) Quit\n");
		scanf("%d", &menu);
		printf("================================\n");
		if (menu == 1) {
			inputEmployeeInfo(emp, num_emp);
			num_emp ++;
		} else if (menu == 2) {
			int emp_id;
			printf("please input employee id (0 is all): ");
			scanf("%d",&emp_id);
			printEmployeeInfo(emp, num_emp, emp_id);
		} else if (menu == 3) {
			// Program Quit
			break;
		}

	}

}

