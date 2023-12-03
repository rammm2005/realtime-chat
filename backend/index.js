const express = require("express");
const cors = require("cors");
const axios = require("axios");

const app = express();
app.use(express.json());
app.use(cors({ origin: true }));

app.post("/authenticate", async (req, res) => {
    const { username } = req.body;

    try {
        const get = await axios.put(
            "https://api.chatengine.io/users/",
            {
                username: username,
                secret: username,
                first_name: username
            },
            { headers: { "private-key": "5f6bf6de-6e02-4bdb-837f-dcbca8e66d65" } }
        );
        return res.status(get.status).json(get.data);

    } catch (err) {
        if (err.response) {
            return res.status(err.response.status).json(err.response.data);
        } else {
            return res.status(500).json({ error: "Internal Server Error" });
        }
    }
});

app.listen(3001);