"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = deactivate;
exports.activate = activate;
const vscode_1 = require("vscode");
const node_1 = require("vscode-languageclient/node");
let client;
function deactivate() {
    return client ? client.stop() : undefined;
}
async function activate(context) {
    const folders = vscode_1.workspace.workspaceFolders;
    if (!folders)
        return;
    else if (folders.length === 0)
        return;
    else if (!folders[0].name.endsWith(".orion"))
        return;
    else {
        vscode_1.window.showInformationMessage("Running Aura (the official Lyrix LSP Client) for '" +
            folders[0].name + "'...");
        const serverPath = "Lyrix";
        const serverOptions = {
            run: {
                command: serverPath,
                transport: node_1.TransportKind.stdio,
                args: ["lsp"]
            },
            debug: {
                command: serverPath,
                transport: node_1.TransportKind.stdio,
                args: ["lsp"]
            }
        };
        const clientOptions = {
            documentSelector: [
                {
                    scheme: "file",
                    language: "Elyra"
                }
            ]
        };
        client = new node_1.LanguageClient("aura", "aura", serverOptions, clientOptions);
        client.start();
    }
}
