SELECT 
    Department.name AS Department,
    Employee.name AS Employee,
    Employee.salary AS Salary
FROM (
    SELECT 
        *,
        DENSE_RANK() OVER (
            PARTITION BY departmentId 
            ORDER BY salary DESC
        ) AS rnk
    FROM Employee
) AS Employee
JOIN Department
    ON Employee.departmentId = Department.id
WHERE Employee.rnk <= 3;