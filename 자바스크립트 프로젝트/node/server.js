import http from 'http';
import url from 'url';
import {parse} from 'querystring' ;

// Create the server
const server = http.createServer((req, res) => {
    const parsedUrl = url.parse(req.url, true);
    const method = req.method;
    const pathname = parsedUrl.pathname;

    //Set the response header content type
    res.setHeader('Content-Type', 'application/json');

    // Route for GET request to "/api/greet"
    if(method === 'GET' && pathname === '/api/greet') {
        const name = parsedUrl.query.name || 'World';
        res.statusCode = 200;
        res.end(JSON.stringify({message:`안녕, ${name}!`}));
    }

    // Route for POST request to "/api/data"
    else if(method === 'POST' && pathname === '/api/data') {
        let body = '';
        req.on('data', chunk => {
            body += chunk.toString();
        })
        req.on('end', ()=> {
            const parsedBody = parse(body);
            res.statusCode = 200;
            res.end(JSON.stringify({receibedData: parsedBody}));
        })
    }

    // Handle 404 for other routes
    else {
        res.statusCode = 404;
        res.end(JSON.stringify({error:'Not Found'}));
    }
});

// Start the server
const PORT = 3000;
server.listen(PORT, ()=> {
    console.log(`Server running on port ${PORT}`);
})