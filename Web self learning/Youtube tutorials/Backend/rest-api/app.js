// Video Link:  https://www.youtube.com/watch?v=fgTGADljAeg

require('dotenv').config()

const express = require('express')
const mongoose = require('mongoose')

const subscriberRouter = require('./routes/subscribers')

const app = express()


mongoose.connect(process.env.DATABASE_URL, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useCreateIndex: true
})
    .then(() => console.log('MongoDB Connected'))
    .catch(err => console.error(err))

app.use(express.json())

app.use('/subscribers', subscriberRouter)


app.listen(5000, () => console.log('Server Started'))
