# Write your MySQL query statement below
SELECT name, bonus
FROM Employee A
LEFT JOIN Bonus B
ON A.empId = B.empId
WHERE bonus IS NULL OR bonus < 1000