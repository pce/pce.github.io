---
layout: post
title: Notes of a collaborative webapp 
description: XERUS - Unmet Needs of a WorldCongress Application     
tags: websockets typescript
---



# XERUS - Unmet Needs of a WorldCongress Application 

Creation of a real-time collaborative client-server gamification application.
One of the requirements is "accessibility", so a browser-based app was a given.

![](/images/xerus.png)   



## Objectives and the TechStack

A simple Client-Server Architecture, collaborative Application.
NestJS and socketio on the Server and React Client.
Websockets for Real-Time-Sharing and in the future a Database to persist Data and User-Auth.  


## Explorations + Decisions


It is a private mono repository and server and client is handled via yarn workspaces. 

### Some History

I've also considered WASM/emscripten or building an app with PlayCanvas, Unreal engine or OF, maybe for my next multiplayer side project.

[1] https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)  
[2] https://playcanvas.com   
[3] https://unrealengine.com   
[4] https://openframeworks.com   


### Client

I tried not to blindly choose any mainstream libraries, but React with Typescript is a solid choice for reasons (VS code/language server supports autocomplete on types, which is really helpful to get things done reliably). 
A fronted router (location[4] or wouter) and native websockets and state management (Zustand). 

While there are many possibilities with 3D in CSS, I didn't want to miss the opportunity to use WebGL and the recently (React 16) introduced Reconciliation alogrithm "React-Fiber", which is based on a somewhat overused Linked List, but seems to work great with R3F (React-Three-Fiber), which allows to use React's scheduling capabilities with ThreeJS [5]. 


[5] https://github.com/tannerlinsley/react-location/blob/main/examples/basic/src/index.tsx 
[6] https://github.com/pmndrs/react-three-fiber

### Server

A small Typescript NestJS Server with SocketIO as WebSocket Gateway  and express as HTTP Backend. First I tried the Ws-library, but then I switched to SocketIO.

[7] https://docs.nestjs.com/websockets/adapter


### Collaborative Data

The standard solutions are OT (Operational Transform) or CRDT (convergent or commutative replicated data type).

- OT: Operations are sent over the wire and concurrent operations are transformed once they are received.
- CvRDTs (convergent replicated data types): State based. Its full local state is sent and is merged with the state of a copy (or optimized, Delta Muations). 
- CmRDTs (commutative replicated data types) operation based, for example only "+b" is transmitted and applied locally (a+b has the same result as b+a and is therfore commutative).


While evaluating industry standards, I came up with a simple solution that works purposefully for an MVP: Broadcast to all clients.
This pragmatic approach is of course only a crutch to be able to test a proof of concept on students of the actual target of the application.  



[8] https://hal.inria.fr/file/index/docid/445975/filename/icdcs09-treedoc.pdf 
[9] https://hal.inria.fr/hal-00934311/file/Replicated_Data_Types-_Specification_Verification_Optimality_Marek_Alexey_Burckhardt_popl14.pdf 
[10] A Conflict-Free Replicated JSON Datatype https://arxiv.org/abs/1608.03960
[11] https://crdt.tech/implementations#yjs-users 
[12] https://github.com/dunhamsteve/notesutils/blob/master/notes.md
[13] https://github.com/automerge/automerge 




## Releases

| Release     |      Value          |  Status |
|-------------|:-------------------:|--------:|
| enphi v0.1  |  very basic Collab  |  DONE   |
|       v0.2  |  Persitence, DB?    |  TODO   |



The repository is currently private and is deployed from github to digitalocean.
