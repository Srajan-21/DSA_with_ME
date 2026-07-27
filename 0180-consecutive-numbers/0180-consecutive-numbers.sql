SELECT DISTINCT
    a.num AS ConsecutiveNums
FROM Logs a
JOIN Logs b
on a.id + 1 = b.id
JOIN Logs c
ON b.id + 1 = c.id
WHERE
    a.num = b.num
AND b.num = c.num;