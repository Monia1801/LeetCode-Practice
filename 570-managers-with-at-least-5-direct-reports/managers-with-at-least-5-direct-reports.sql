SELECT e.name AS name
FROM Employee e
LEFT JOIN Employee m
ON e.id=m.managerId 
GROUP BY m.managerId
HAVING COUNT(m.managerId)>=5;