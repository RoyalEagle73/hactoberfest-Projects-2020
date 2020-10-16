var http = require('https');
var fs = require('fs');
exports.downloadInstagramData = (req,res)=>{
    var url = req.body.url;
    
    if(url != null){
        url = url.substring(0, url.indexof("?"));
    }
    

    var request = require('request');
    request(url+'?__a=1', function (error, response, body) {
        if (!error && response.statusCode == 200) {
            console.log(body) // Print the google web page.
            var a = JSON.parse(body);
            console.log(a.graphql.shortcode_media.video_url);

            // res.redirect(a.graphql.shortcode_media.video_url);
            // res.json({
            //     success:true,
            //     id: 101,
            //     output: a.graphql.shortcode_media.video_url
            // })
            
            res.render('insta_d.ejs',{
                url: a.graphql.shortcode_media.video_url
            })
            // var file = fs.createWriteStream("rakoo_instad_"+new Date().getTime());
            // http.get(a.graphql.shortcode_media.video_url, function(response) {
            //   response.pipe(file);
            //   file.on('finish', function() {
            //     // file.close(cb);
            //   });
            // });

         }
    })


}
exports.viewInstagram = (req,res)=>{
    res.render('insta.ejs');
}