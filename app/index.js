const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");
const path = require('path');

const app = express();

app.use(cors());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use('/static', express.static(path.join(__dirname, 'public/static')))

let state = "inactivo";

app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname + '/public/index.html'));
});

app.get('/state', function (req, res) {
    res.send(state);
});

app.get('/toggle', function (req, res) {
    if (state === "inactivo"){
        state = "activo";
    } else {
        state = "inactivo";
    }
    
    res.send(state).status(200);
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
    console.log(`App funcionando en el puerto: ${PORT}.`);
});

