SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    t.country,
    (
        COUNT(t.state)
    ) AS trans_count,
    (
        SUM(t.state = 'approved')
    ) AS approved_count,
    (
        SUM(t.amount)
    ) AS trans_total_amount,
    (
        -- SUM(CASE WHEN t.state = 'approved' THEN t.amount ELSE 0 END)
        SUM(IF(t.state = 'approved' , t.amount , 0))
        -- SUM(t.amount WHERE t.state = 'approved') THIS IS NOT VALID SYNTAX
    ) AS approved_total_amount
FROM 
    Transactions t
GROUP BY 
    DATE_FORMAT(trans_date, '%Y-%m'),
    country;