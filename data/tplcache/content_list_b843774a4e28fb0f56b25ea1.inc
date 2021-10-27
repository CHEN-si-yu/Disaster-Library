<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>" />
<title>�ĵ����� - ��Ա���� - <?php echo $cfg_webname; ?></title>
<link href="templets/style/base.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="templets/js/j.js"></script>
<script type="text/javascript" src="templets/js/load.js"></script>
<script type="text/javascript" src="templets/js/leftmenu.js"></script>
<script type="text/javascript">
  function viewArc(aid){
	  window.open("<?php echo $GLOBALS['cfg_phpurl']; ?>/view.php?aid="+aid);
  }
  function editArc(aid,channelid){
	  location = "archives_do.php?dopost=edit&channelid="+channelid+"&aid="+aid;
  }
  function delArc(aid){
	  if(window.confirm('��ȷ��Ҫɾ����ƪ�ĵ���?')) location="archives_do.php?aid="+aid+"&dopost=delArc";
  }
</script>
</head>
<body>
<div id="main">
  <?php include(DEDEMEMBER."/templets/head.htm"); ?>
  <div id="content" class="w960 clearfix">
    <?php include(DEDEMEMBER."/templets/menu.php"); ?>
    <div id="mcpmain">
      <div id="appTab">
        <ul>
          <li class="thisTab"><a href="#"><span><?php echo $positionname; ?></span></a></li>
        </ul>
      </div>
      <ul class="tabSub">
        <li <?php echo ($arcrank=='')? "class='thisTab'" : "";?>><a href="content_list.php?channelid=<?php echo $channelid;?>"><span>ȫ��</span></a></li>
        <li <?php echo ($arcrank=='1')? "class='thisTab'" : "";?>><a href="content_list.php?channelid=<?php echo $channelid;?>&arcrank=1"><span>�����</span></a></li>
        <li <?php echo ($arcrank=='-1')? "class='thisTab'" : "";?>><a href="content_list.php?channelid=<?php echo $channelid;?>&arcrank=-1"><span>δ���</span></a></li>
        <li <?php echo ($arcrank=='-2')? "class='thisTab'" : "";?>><a href="content_list.php?channelid=<?php echo $channelid;?>&arcrank=-2"><span>���˻�</span></a></li>
      </ul>
      <div id="mainCp">
        <!--������Ϣ��ʾ -->
        <h3 class="meTitle">�ѷ���<?php echo $positionname; ?><small>(��������������<?php echo $positionname; ?>)</small></h3>
        <table width="100%" border="0" cellpadding="0" cellspacing="0" class="list">
          <thead>
            <tr>
              <th width="40%">���±���</th>
              <th width="15%">��Ŀ </th>
              <th width="10%">״̬ </th>
              <th width="10%">��� </th>
              <th width="11%">����ʱ�� </th>
              <th width="25%">����</th>
            </tr>
          </thead>
          <tbody>
          <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
            <tr>
              <td class="tabTitle"><a href='<?php echo $cfg_phpurl; ?>/view.php?aid=<?php echo $fields['id']; ?>' target='_blank'><?php echo $fields['title'];  echo IsPicArchives($fields['litpic']); ?></a></td>
              <td align="center"><?php echo $fields['typename']; ?></td>
              <td align="center"><?php
if($fields['arcrank']>=0) echo "�����";
else if($fields['arcrank']==-2) echo "<font color='blue'>���˻�</font>";
else echo "<font color='red'>δ���</font>";
?></td>
              <td align="center"><?php echo $fields['click']; ?></td>
              <td><?php echo GetDateMk($fields['senddate']); ?></td>
              <td align="center" class="doPost"><?php
if($fields['arcrank']<0 || $dtime - $fields['senddate'] < $maxtime)
{
?>
                <a href="javascript:editArc(<?php echo $fields['id']?>,<?php echo $fields['channel']?>);">�޸�</a> | <a href="javascript:delArc(<?php echo $fields['id']?>);">ɾ��</a> |
                <?php
}
else
{
	echo "<span class='gray'>�� | ɾ | </span>";
}
?>  <a href="javascript:viewArc(<?php echo $fields['id']; ?>);">Ԥ��</a></td>
            </tr>
         <?php
}
}?>
          </tbody>
          <tfoot>
            <tr>
              <td colspan="6"><div class="pageList"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div></td>
            </tr>
          </tfoot>
        </table>
      </div>
      <!--���������� -->
    </div>
  </div>
<?php include(DEDEMEMBER."/templets/foot.htm"); ?>  
</div>
</body>
</html>