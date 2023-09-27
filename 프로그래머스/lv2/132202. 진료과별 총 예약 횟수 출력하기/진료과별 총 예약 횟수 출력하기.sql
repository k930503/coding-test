# select mcdp_cd as '진료과 코드', count(apnt_no) as '5월예약건수' from appointment where date_format(apnt_ymd, '%Y-%m') = '2022-05' and apnt_cncl_yn = 'N' group by '진료과 코드' order by '5월예약건수', '진료과 코드'

SELECT  
        MCDP_CD as '진료과 코드',
        count(PT_NO) as '5월예약건수'
from    APPOINTMENT 
where   date_format(APNT_YMD, '%Y-%m') = '2022-05'
group by 1
order by 2 asc , 1 asc