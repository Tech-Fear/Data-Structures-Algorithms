# Write your MySQL query statement below
SELECT DEPT.name AS Department,EMP.name as Employee, EMP.salary as Salary from Department DEPT,
Employee EMP where EMP.departmentId=DEPT.id AND (EMP.departmentId,salary) in (SELECT departmentId, max(salary) from Employee group by departmentId )