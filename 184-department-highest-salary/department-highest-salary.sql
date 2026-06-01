-- # Write your MySQL query statement below
-- SELECT D.name AS Department,E.name AS Employee,E.salary AS Salary
-- FROM Employee AS E
-- LEFT JOIN Department AS D
-- ON E.departmentId=D.id
-- WHERE E.salary=(
--     SELECT MAX(salary)
--     FROM Employee
--     WHERE departmentId=E.departmentId
-- );

select d.name as department,e.name as employee,e.salary as salary
from employee as e
left join department as d
on e.departmentid=d.id
WHERE e.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId = e.departmentId
);