const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const path = require('path');

const app = express();
const port = 3000;

// Connect to MongoDB
mongoose.connect('mongodb+srv://realestate:9945994323@cluster0.vfyccaa.mongodb.net/feedback', {
    useNewUrlParser: true,
    useUnifiedTopology: true
}).then(() => console.log('MongoDB connected...'))
  .catch(err => console.log('MongoDB connection error:', err));

// Middleware
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')));

// Feedback Schema
const feedbackSchema = new mongoose.Schema({
    name: { type: String, required: true },
    email: { type: String, required: true },
    message: { type: String, required: true }
});

const Feedback = mongoose.model('Feedback', feedbackSchema);

// Routes
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'form.html'));
});

app.post('/feedback', (req, res) => {
    const newFeedback = new Feedback({
        name: req.body.name,
        email: req.body.email,
        message: req.body.message
    });

    newFeedback.save()
        .then(feedback => {
            res.send('Thank you for your feedback!');
        })
        .catch(err => {
            console.error('Error saving feedback:', err);
            res.status(500).send('Unable to save feedback');
        });
});

app.listen(port, () => {
    console.log(`Server running on port ${port}`);
});
