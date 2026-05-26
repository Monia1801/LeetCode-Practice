# Write your MySQL query statement below
SELECT emp.name as Employee
FROM Employee as emp
JOIN Employee as man
ON emp.managerId=man.id
WHERE emp.salary>man.salary;
