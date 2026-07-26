SELECT
    user_id,
    COUNT(follower_id) AS followers_count
FROM
    Followers f
GROUP BY
    user_id
ORDER BY user_id;