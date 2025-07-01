import express from 'express';
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  if(req.session.userid){
    res.send(`Here is the information for you (${req.session.userid})`)
  } else{
    res.status(401).send("Error: you must be logged in")
  }
});


router.post('/login', (req, res) => {

  if(req.body.username == "kylethayer" && req.body.password == "asdasd"){
    req.session.userid = "kylethayer"
    res.send("you logged in")
  } else if(req.body.username == "anotheruser" && req.body.password == "pwd"){
    req.session.userid = "anotheruser"
    res.send("you logged in")
  } else {
    res.send("wrong login info")
  }
})

router.post('/logout', (req, res) => {
  req.session.destroy()
  res.send("you are logged out")
})

export default router;
