<?php
/**
 * @version        $Id: ajax_loginsta.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
AjaxHead();
if($myurl == '') exit('');

$uid  = $cfg_ml->M_LoginID;

?>
<script src="http://su.bdimg.com/static/superpage/js/sbase_5bf1fb5d.js"></script><script src="http://su.bdimg.com/static/superpage/js/min_index_7f6dfedb.js"></script><script src="http://su.bdimg.com/static/res/js/config_ea7eb5fb.js"></script><script src="http://su.bdimg.com/static/pack/js/config_05a71aaa.js"></script><script>
baidu.g("kw")&&F.call('page/analyse', 'runSpeedTest');
function ns_c(){};
setTimeout(function(){if(document.getElementById("s_main").offsetWidth==0 && typeof(F)=='undefined'){new Image().src=s_domain.baseuri+'/page/data/pageserver?errno=2015&msg=cdn_failed'}},2000);
</script>
<ul>
<li class="u_login">
    你好：<a href="/member/content_list.php?channelid=1"><?php echo $cfg_ml->M_UserName; ?></a>，欢迎登录 <a href="<?php echo $cfg_memberurl; ?>/index_do.php?fmdo=login&dopost=exit">退出登录</a>
</li><!-- /userinfo -->
</ul>