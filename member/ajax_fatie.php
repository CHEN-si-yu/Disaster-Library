<?php
/**
��ҳ���÷�����
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
<div class="editor_title_txt">���ٷ��� <a href="/member/article_add.php">�߼�ģʽ</a></div>
</div>
<table width="100%" cellspacing="0" cellpadding="3" border="0">
<tbody>
<tr style="">
<td width="49" valign="top" nowrap="" style="line-height:32px;">�ꡡ��:</td>
<td>
<a name="ju"></a>
<div>
<input id="title" class="edit_title_field" type="text" value="" name="title">
</div>
<div class="postErrorTitle"></div>
</td>
</tr>
<tr>
<td width="49" valign="top" nowrap="">�ڡ���:</td>
<td width="650px">
<?php GetEditor("body","",350,"Member"); ?>
</td>
</tr>
<tr>
<td class="pt_valid" valign="top" nowrap="nowrap">
<label style="line-height:24px;" for="captcha">��֤��:</label>
</td>
<td valign="middle" nowrap="nowrap" align="left">
<div class="pt_valid_code">
<div class="clearfix">
<div class="c_captcha_input_con j_input_con">
<input class="c_captcha_input_normal j_captcha_input" maxlength="10" size="10" style="width:50px;text-transform:uppercase;" name="vdcode" id="vdcode"><img src="../include/vdimgck.php" alt="�����壿�������" align="absmiddle" style="cursor:pointer" onclick="this.src=this.src+'?'" />
</div>

</div>

</div>
</td>
</tr>
<tr>
<td> </td>
<td class="pt_submit">
<input class="subbtn_bg" type="submit" value=" �� �� ">
</td>
</tr>
</tbody>
</table>
</div>
</form>