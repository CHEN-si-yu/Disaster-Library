var passport=passport||window.passport||{};passport._modulePool=passport._modulePool||{};passport._define=passport._define||function(a,b){passport._modulePool[a]=b&&b()};passport._getModule=passport._getModule||function(a){return passport._modulePool[a]};passport._use=passport._use||function(f,g,h){var e={"http:":"http://passport.bdimg.com","https:":"https://passport.baidu.com"},d=e[window.location.protocol.toLowerCase()]+g;var c=f+".js";moduleInstance=passport._getModule(c);if(moduleInstance){h&&h(moduleInstance)}else{a(d,true)}function b(){var i=passport._getModule(c);if(i){h&&h(i)}else{throw new Error("load "+c+"module script error.")}}function a(k,i){if(i){var o=document,m=o.createElement("SCRIPT");m.type="text/javascript";m.charset="UTF-8";var j=k.split("?")[0];var n=Math.round(Math.random()*1000);var l=new Date().getTime();if(m.readyState){m.onreadystatechange=function(){if(m.readyState=="loaded"||m.readyState=="complete"){m.onreadystatechange=null;if(100==n){var p=new Date().getTime()-l;(new Image()).src="http://nsclick.baidu.com/v.gif?pid=111&type=1023&url="+encodeURIComponent(j)+"&time="+p}b()}}}else{m.onload=function(){if(100==n){var p=new Date().getTime()-l;(new Image()).src="http://nsclick.baidu.com/v.gif?pid=111&type=1023&url="+encodeURIComponent(j)+"&time="+p}b()}}if(100==n){m.src=j+"?t="+Math.random()}else{m.src=k}o.getElementsByTagName("head")[0].appendChild(m)}else{var o=document,m=o.createElement("SCRIPT");m.type="text/javascript";m.charset="UTF-8";m.src=k;o.getElementsByTagName("head")[0].appendChild(m);if(m.readyState){m.onreadystatechange=function(){if(m.readyState=="loaded"||m.readyState=="complete"){m.onreadystatechange=null;b()}}}else{m.onload=function(){b()}}}}};passport.use=passport.use||function(d,c,f){var b=(c&&c.tangram===false)?"":"_tangram";if(d=="reg"&&c&&c.regPhoneOnly){d="regPhone"}var e={login:"/passApi/js/login_67b0091d.js",login_tangram:"/passApi/js/login_tangram_6138d88f.js",reg:"/passApi/js/reg_14e5354c.js",reg_tangram:"/passApi/js/reg_tangram_37e35339.js",regPhone:"/passApi/js/regPhone_73fd4af8.js",regPhone_tangram:"/passApi/js/regPhone_tangram_39ec01e0.js",fillUserName:"/passApi/js/fillUserName_cb6f8b90.js",fillUserName_tangram:"/passApi/js/fillUserName_tangram_54bd97ca.js"},a=d+b;if(arguments.length==2){f=c}if(c&&c.tangramInst){passport.tangramInst=c.tangramInst}passport._use(a,e[a],f)};