var home = require('../app/controllers/home');

//you can include all your controllers

module.exports = function (app) {

   app.get('/',home.viewInstagram)

   app.post('/id',home.downloadInstagramData);
   
}
