<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $GLOBALS['cfg_soft_lang']; ?>" />
<title>�û����ۣ�<?php echo $GLOBALS['title']; ?></title>
<link href="<?php echo $GLOBALS['cfg_templets_skin']; ?>/style/dedecms.css" rel="stylesheet" media="screen" type="text/css" />
<script language="javascript" type="text/javascript" src="<?php echo $GLOBALS['cfg_cmsurl']; ?>/include/dedeajax2.js"></script>
<script language="javascript">
function postBadGood(ftype,fid)
{
	var taget_obj = document.getElementById(ftype+fid);
	var saveid = GetCookie('badgoodid');
	if(saveid != null)
	{
		 var saveids = saveid.split(',');
		 var hasid = false;
		 saveid = '';
		 j = 1;
		 for(i=saveids.length-1;i>=0;i--)
		 {
		 	  if(saveids[i]==fid && hasid) continue;
		 	  else {
		 	  	if(saveids[i]==fid && !hasid) hasid = true;
		 	  	saveid += (saveid=='' ? saveids[i] : ','+saveids[i]);
		 	  	j++;
		 	  	if(j==10 && hasid) break;
		 	  	if(j==9 && !hasid) break;
		 	  }
		 }
     if(hasid) { alert('���ղ��ѱ�������ร�'); return false; }
     else saveid += ','+fid;
		 SetCookie('badgoodid',saveid,1);
	}
	else
	{
		SetCookie('badgoodid',fid,1);
	}
	//document.write("feedback.php?action="+ftype+"&fid="+fid);
	//return;
  myajax = new DedeAjax(taget_obj,false,false,'','','');
  myajax.SendGet2("feedback.php?aid=<?php echo $GLOBALS['aid']; ?>&action="+ftype+"&fid="+fid);
  DedeXHTTP = null;
}

function ajaxFeedback(aid, fid, type)
{
	
	var taget_obj = $DE('ajaxfeedback_'+fid);
	if(taget_obj.innerHTML == '')
	{
		var myajax = new DedeAjax(taget_obj, true, true, '', 'x');
		myajax.SendGet2("<?php echo $GLOBALS['cfg_phpurl']; ?>/feedback.php?aid="+aid+"&fid="+fid+"&action=quote&type=ajax");
		eval('var result = typeof CKEDITOR.instances.msg_'+fid);
		if(result != 'undefined')
		{
			// ɾ��ʵ��
			eval('var edit = CKEDITOR.instances.msg_'+fid);
			CKEDITOR.remove(edit);
		}
		CKEDITOR.replace(document.getElementById('msg_'+fid) , CKEDITOR.instances.msg.config);
		scroll(0, taget_obj.offsetTop - 120);
		var formname = 'f = document.ajaxfeedback_'+fid;
		eval(formname);
		if(f.validate)
		{
			if($DE('vdimg_'+fid)) $DE('vdimg_'+fid).src = "<?php echo $GLOBALS['cfg_cmsurl']; ?>/include/vdimgck.php?"+f.validate.value;
			f.validate.value = '';
		}
		
		DedeXHTTP = null;
	}
}

function ajaxQuotePost(fid)
{
	var formname = 'f = document.ajaxfeedback_'+fid;
	eval(formname);
	//var f = document.formname;
	//var f = f[0];
	var nvalidate = '';
	var nnotuser = '';
	var nusername = '';
	var npwd = '';
	var taget_obj = $DE('commetcontentNew');
	var waithtml = "<div style='line-height:30px'><img src='<?php echo $GLOBALS['cfg_cmsurl']; ?>/images/loadinglit.gif' />���ڷ�����...</div>";
	eval('var msg = CKEDITOR.instances.msg_'+fid+'.getData()');

	if(f.validate)
	{
		if(f.validate.value=='') {
			alert("����д��֤�룡");
			return;
		}
		else {
			nvalidate = f.validate.value;
		}
	}
	var myajax = new DedeAjax(taget_obj, false, true, '', '', waithtml);
	
	if(f.notuser.checked) nnotuser = '1';
	if(f.username) nusername = f.username.value;
	if(f.pwd) npwd = f.pwd.value;
	
	myajax.sendlang = '<?php echo $GLOBALS['cfg_soft_lang']; ?>';
	myajax.AddKeyN('dopost', 'send');
	myajax.AddKeyN('aid', '<?php echo $GLOBALS['aid']; ?>');
	myajax.AddKeyN('fid', f.fid.value);
	myajax.AddKeyN('type', 'ajax');
	myajax.AddKeyN('comtype', f.comtype.value);
	myajax.AddKeyN('isconfirm','yes');
	
	myajax.AddKeyN('typeid', f.typeid.value);
	myajax.AddKeyN('quotemsg', f.quotemsg.value);
	myajax.AddKeyN('validate', nvalidate);
	myajax.AddKeyN('notuser', nnotuser);
	myajax.AddKeyN('username', nusername);
	myajax.AddKeyN('pwd', npwd);
	myajax.AddKeyN('msg', msg);
	myajax.SendPost2('<?php echo $GLOBALS['cfg_phpurl']; ?>/feedback_ajax.php');
	//alert(f.quotemsg.value);
	if($DE('ajaxfeedback_'+fid).innerHTML != null)
	{
		$DE('ajaxfeedback_'+fid).innerHTML = '';
	}
	scroll(0, taget_obj.offsetTop);
	taget_obj.removeAttribute('id');

}
</script>
<body class="commentpage">
<div class="header">
  <div class="top w960 center">
    <div class="title">
      <h1><a href="<?php echo $GLOBALS['cfg_basehost']; ?>" title="<?php echo $GLOBALS['cfg_webname']; ?>"><img src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/images/logo.gif" height="54" width="216" alt="<?php echo $GLOBALS['cfg_webname']; ?>"/></a> </h1>
    </div>
    <!-- /title -->
    <div class="welcome">
      <?php if($cfg_ml->M_ID <= 0) { ?>
      ����,��ӭ��������վ,����û�е�½,����<a href="<?php echo $cfg_memberurl; ?>/index.php">��½</a>����<a href="<?php echo $cfg_memberurl; ?>/index_do.php?fmdo=user&dopost=regnew">ע��</a>.
      <?php }else{  echo $cfg_ml->M_LoginID; ?>,��ӭ���ĵ�½�� <a href="<?php echo $cfg_memberurl; ?>/index.php">��Ա����</a> | <a href="<?php echo $cfg_memberurl; ?>/edit_fullinfo.php">�ҵ�����</a> | <a href="<?php echo $cfg_memberurl; ?>/index.php?uid=<?php echo urlencode($cfg_ml->M_LoginID);?>">�ҵĿռ�</a> | <a href="<?php echo $cfg_memberurl; ?>/index_do.php?fmdo=login&dopost=exit">�˳���¼</a>
      <?php
        }
        ?>
    </div>
    <!-- /banner -->
  </div>
  <!-- /top -->
</div>
<!-- /nav -->
</div>
<!-- /header -->
<div class="w960 clear center mt1 cmt-box">
  <div class="sp-title">
    <h2>����:<a href='<?php echo $GLOBALS['arcurl']; ?>'><?php echo $GLOBALS['title']; ?></a></h2>
  </div>
  <div>
    <dl class="tbox">
      <dt> <strong>�����б����������۽������ѱ�����˿���������������վͬ����۵��֤ʵ��������</strong> <span class="label"> <a href='feedback.php?aid=<?php echo $GLOBALS['aid']; ?>&ftype=good' <?php if($ftype=='good') echo "class='thisclass'"; ?>>ֻ������</a> <a href='feedback.php?aid=<?php echo $GLOBALS['aid']; ?>&ftype=bad' <?php if($ftype=='bad') echo "class='thisclass'"; ?>>ֻ������</a> <a href='feedback.php?aid=<?php echo $GLOBALS['aid']; ?>&ftype=feedback' <?php if($ftype=='feedback') echo "class='thisclass'"; ?>>ֻ������</a> <a href='feedback.php?aid=<?php echo $GLOBALS['aid']; ?>' <?php if($ftype=='') echo "class='thisclass'"; ?>>ȫ������</a> </span> </dt>
      <dd>
        <div class="dede_comment">
          <div class='decmt-box1'>
            <ul>
            <li id="commetcontentNew"></li>
            
              <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{

  if($fields['userid']!='') $spaceurl = $cfg_basehost.'/member/index.php?uid='.$fields['userid'];
  else $spaceurl = "#";
  if($fields['username']=='����') $spaceurl = "#";
  $fields['bgimg'] = 'cmt-neu.gif';
  $fields['ftypetitle'] = '���û���ʾ����';
  if($fields['ftype']=='bad') {
  	$fields['bgimg'] = 'cmt-bad.gif';
  	$fields['ftypetitle'] = '���û���ʾ����';
  }
  else if($fields['ftype']=='good') {
  	$fields['bgimg'] = 'cmt-good.gif';
  	$fields['ftypetitle'] = '���û���ʾ����';
  }
  if(empty($fields['mface']))
  {
    if($fields['sex']=="Ů") $fields['mface']="/member/templets/images/dfgirl.png";
    else $fields['mface']="/member/templets/images/dfboy.png";
  }
?>
              <li> <a href='<?php echo $spaceurl; ?>' class='plpic'><img src='<?php echo $fields['mface'];?>'  height='40' width='40'/></a> <span class="title"> <?php echo $fields['username']; ?><img src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/images/<?php echo $fields['bgimg']; ?>" /></span>
                <div class="comment_act"><span class="fr"> <span id='goodfb<?php echo $fields['id']; ?>'><a href="#" onclick="postBadGood('goodfb',<?php echo $fields['id']; ?>)">֧��</a>[<?php echo $fields['good']; ?>]</span> <span id='badfb<?php echo $fields['id']; ?>'><a href="#" onclick="postBadGood('badfb',<?php echo $fields['id']; ?>)">����</a>[<?php echo $fields['bad']; ?>]</span> <span class='quote'><a href="javascript:ajaxFeedback(<?php echo $fields['id']; ?>,<?php echo $fields['id']; ?>,'quote');">����</a></span></span> <?php echo MyDate('m-d H:i',$fields['dtime']); ?>����</div>
                <p>
                <?php
                echo RemoveXSS(Quote_replace(parseSmileys($fields['msg'],$cfg_cmspath.'/images/smiley')));
                ?></p>
              </li>
               <div id="ajaxfeedback_<?php echo $fields['id']; ?>"></div>
              <?php
}
}
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listitem'] = 'info,index,end,pre,next,pageno';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

            </ul>
          </div>
        </div>
        <!-- /dede_comment -->
      </dd>
    </dl>
  </div>
  <div class="mt1">
    <dl class="tbox">
      <dt> <strong>��������</strong> </dt>
      <dd>
        <div class="dede_comment_post">
          <form action="feedback.php" method="post" name="feedback">
            <input type="hidden" name="action" value="send" />
            <input type="hidden" name="comtype" value="comments">
            <input type="hidden" name="aid" value="<?php echo $aid; ?>" />
            <input type="hidden" name="isconfirm" value="yes" />
            <div class="dcmp-title"> <small>���Ծ����ػ�������ص����߷��棬�Ͻ�����ɫ�顢���������������ۡ�</small> </div>
            <!-- /dcmp-title -->
            <div class="dcmp-stand"> <strong>����:</strong>
              <input type="radio" name="feedbacktype" checked="1" value="feedback" id="dcmp-stand-neu" />
              <label for="dcmp-stand-neu"><img src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/images/cmt-neu.gif" />����</label>
              <input type="radio" name="feedbacktype" value="good" id="dcmp-stand-good" />
              <label for="dcmp-stand-good"><img src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/images/cmt-good.gif" />����</label>
              <input type="radio" name="feedbacktype" value="bad" id="dcmp-stand-bad" />
              <label for="dcmp-stand-bad"><img src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/images/cmt-bad.gif" />����</label>
            </div>
            <!-- /dcmp-stand -->
            <div class="clr"></div>
            <!-- /dcmp-mood -->
            <div class="dcmp-content1">
            <script type="text/javascript">
					//<![CDATA[
					window.CKEDITOR_BASEPATH='<?php echo $GLOBALS['cfg_cmsurl']; ?>/include/ckeditor/';
					//]]>
                    </script>
            <script type="text/javascript" src="<?php echo $GLOBALS['cfg_cmsurl']; ?>/include/ckeditor/ckeditor.js?t=B8DJ5M3"></script>
            <?php
GetEditor('msg','',100,'Feedback','print','false',true);
?>
            </div>
            <!-- /dcmp-content -->
            <div class="dcmp-post">
              <!--δ��½-->
              <div class="dcmp-userinfo"> �û�����
                <?php if($cfg_ml->M_ID <= 0) { ?>
                <input name="username" type="text" id="username" size="10" class="nb" />
                ��<a href="../member/index_do.php?fmdo=user&dopost=regnew" target="_blank"><u>ע�����û�</u></a>��
                <?php
                    }else{  echo $cfg_ml->M_LoginID."&nbsp;"; }
                   ?>
                <input name="notuser" type="checkbox" id="notuser" value="1" />
                ��������
                <?php if(preg_match("/4/",$safe_gdopen)){ ?>
                ��֤�룺
                <input name="validate" type="text" id="validate" size="10" style="height:18px;width:60px;margin-right:6px;text-transform:uppercase;" class="nb" />
                <img src='../include/vdimgck.php' width='60' height='24' style="cursor:pointer" onclick="this.src=this.src+'?'" title="����Ҹ���ͼƬ" alt="����Ҹ���ͼƬ" />
                <?php } ?>
                <button type="submit" class="btn-2">��������</button>
              </div>
              <!-- /dcmp-submit -->
            </div>
            <!-- /dcmp-post -->
          </form>
        </div>
        <!-- /dede_comment_post -->
      </dd>
    </dl>
  </div>
</div>
<?php include $this->CompilerInclude("../default/footer.htm");
 ?>
<!-- /footer -->
</body>
</html>