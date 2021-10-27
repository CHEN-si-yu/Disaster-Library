<?php
$z[0]=Array("global","",255,281);
$z[0][4]['name']="cfg_webname";
$z[1]=Array("include","",716,751);
$z[1][4]['filename']="head.htm";
$z[2]=Array("global","",1004,1030);
$z[2][4]['name']="cfg_webname";
$z[3]=Array("global","",1034,1060);
$z[3][4]['name']="cfg_webname";
$z[4]=Array("sql","共有主题：[field:c/]\r\n个",1550,1658);
$z[4][4]['sql']="select count(ID) as c from dede_archives where channel=1";
$z[5]=Array("sql","[field:c/]\r\n个",1777,1859);
$z[5][4]['sql']="select count(id) as c from dede_feedback";
$z[6]=Array("sql","[field:c/]名",1998,2077);
$z[6][4]['sql']="select count(mid) as c from dede_member";
$z[7]=Array("freelist","",2712,2728);
$z[8]=Array("pagelist","",2869,2940);
$z[8][4]['listitem']="info,index,end,pre,next,pageno";
$z[8][4]['listsize']="5";
$z[9]=Array("sql","[field:uname/]",3738,3835);
$z[9][4]['sql']="select uname from dede_member order by mid desc limit 1";
$z[10]=Array("sql","[field:c/]名",3887,3966);
$z[10][4]['sql']="select count(mid) as c from dede_member";
$z[11]=Array("sql","[field:c/]篇",4079,4203);
$z[11][4]['sql']="SELECT count( id ) AS c FROM dede_archives WHERE pubdate > UNIX_TIMESTAMP(CURDATE())";
$z[12]=Array("sql","[field:c\r\n/]篇",4316,4456);
$z[12][4]['sql']="SELECT count( ID ) AS c FROM dede_archives WHERE FROM_UNIXTIME(pubdate,'%m' ) =month(curdate( ))";
$z[13]=Array("channel","\r\n<li><a href='[field:typeurl/]'>[field:typename/]</a></li>\r\n",4849,4959);
$z[13][4]['type']="top";
$z[13][4]['row']="10";
$z[14]=Array("flink","",5291,5328);
$z[14][4]['linktype']="2";
$z[14][4]['row']="24";
$z[15]=Array("global","",6789,6817);
$z[15][4]['name']="cfg_memberurl";
$z[16]=Array("include","",8464,8501);
$z[16][4]['filename']="footer.htm";

?>