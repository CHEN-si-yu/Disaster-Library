<?php
/**
首页调用发帖框
 */
require_once(dirname(__FILE__)."/config.php");
AjaxHead();
if($myurl == '') exit('');

$uid  = $cfg_ml->M_LoginID;

?>
<form name="addcontent" action="/member/article_add.php" method="post" enctype="multipart/form-data" onsubmit="return checkSubmit();">
<input type="hidden" name="dopost" value="save" />
<input type="hidden" name="channelid" value="1" />
<input name="tags" type="hidden" id="tags" maxlength="100" class="intxt" value=""/>          
<input type="hidden" name="writer" id="writer" value="<?php echo $cfg_ml->M_UserName; ?>" maxlength="100" class="intxt" style="width:219px"/>
<input type="hidden" name="typeid" value="2" maxlength="100" class="intxt" style="width:219px"/>
<input type="hidden" name="mtypesid" value="0" maxlength="100" class="intxt" style="width:219px"/>
<input type="hidden" name="description" value="" class="intxt" style="width:219px"/>
<div id="edit_parent">
<div class="new_tiezi_tip">
<div class="editor_title_txt">快速发贴 <a href="/member/article_add.php">高级模式</a></div>
</div>
<table width="100%" cellspacing="0" cellpadding="3" border="0">
<tbody>
<tr style="">
<td width="49" valign="top" nowrap="" style="line-height:32px;">标　题:</td>
<td>
<a name="ju"></a>
<div>
<input id="title" class="edit_title_field" type="text" value="" name="title">
</div>
<div class="postErrorTitle"></div>
</td>
</tr>
<tr>
<td width="49" valign="top" nowrap="">内　容:</td>
<td width="650px">
<?php GetEditor("body","",350,"Member"); ?>
</td>
</tr>
<tr>
<td class="pt_valid" valign="top" nowrap="nowrap">
<label style="line-height:24px;" for="captcha">验证码:</label>
</td>
<td valign="middle" nowrap="nowrap" align="left">
<div class="pt_valid_code">
<div class="clearfix">
<div class="c_captcha_input_con j_input_con">
<input class="c_captcha_input_normal j_captcha_input" maxlength="10" size="10" style="width:50px;text-transform:uppercase;" name="vdcode" id="vdcode"><img src="../include/vdimgck.php" alt="看不清？点击更换" align="absmiddle" style="cursor:pointer" onclick="this.src=this.src+'?'" />
</div>

</div>

</div>
</td>
</tr>
<tr>
<td> </td>
<td class="pt_submit">
<input class="subbtn_bg" type="submit" value=" 发 表 ">
</td>
</tr>
</tbody>
</table>
</div>
</form>