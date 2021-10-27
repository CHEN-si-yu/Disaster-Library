{dede:list  pagesize='3' col='1' titlelen='60' orderby='pubdate' orderway='desc' 
 channel='1' }<li class="j_thread_list" class="j_thread_list"><div class="threadlist_li_left j_threadlist_li_left">
	<div title="[field:click/]次阅读" class="threadlist_rep_num j_rp_num">[field:click/]</div>
</div>
<div class="threadlist_li_right">
	<div class="threadlist_lz clearfix">
		<div class="threadlist_text threadlist_title j_th_tit  notStarList ">
			<a href="[field:arcurl/]" title="[field:title/]" class="j_th_tit">[field:title/]</a>
			</span>
			
		</div>
		<div class="threadlist_author">
			<span class="tb_icon_author "></span>
		</div>
	</div>
	<div class="threadlist_detailclearfix">	
		<div class="threadlist_text">
			<div class="threadlist_abs threadlist_abs_onlyline">[field:description/]...</div>
[field:array runphp='yes']@me = (strpos(@me['litpic'],'defaultpic') ? "" : "<ul class='threadlist_media j_threadlist_media'><li><div class='vpic_wrap'><img src='{@me['litpic']}' class='threadlist_pic j_m_pic ' /></div><div class='threadlist_pic_highlight j_m_pic_light'></div></li></ul>"); [/field:array]				
		</div>
		<div class="threadlist_author">
                        <span class="tb_icon_author_rely j_replyer" title="发布者">[field:writer/]</span>
			<span title="发布时间">[field:pubdate function="MyDate('m-d',@me)"/]</span>
		</div>
	</div>
</div>
<div class="clear"></div>
</li>{/dede:list}