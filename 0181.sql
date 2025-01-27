# Write your MySQL query statement belo
SELECT A.name AS Employee
FROM Employee A
INNER JOIN Employee B 
ON A.managerId = B.id
WHERE A.salary > B.salary;