import { ExtensionContext, workspace, window } from "vscode";
import { LanguageClient, ServerOptions, TransportKind, LanguageClientOptions} from "vscode-languageclient/node";

let client: LanguageClient;

export function deactivate(): Thenable<void> | undefined
{
    return client ? client.stop() : undefined;
}

export async function activate(context: ExtensionContext)
{
    const folders = workspace.workspaceFolders;
    if(!folders)
        return;
    else if(folders.length === 0)
        return;
    else if(!folders[0].name.endsWith(".orion"))
        return;
    const serverPath = "Lyrix";
    const serverOptions: ServerOptions =
    {
        run:
        {
            command: serverPath,
            transport: TransportKind.stdio,
            args: ["lsp"]
        },
        debug:
        {
            command: serverPath,
            transport: TransportKind.stdio,
            args: ["lsp"]
        }
    };
    const clientOptions: LanguageClientOptions =
    {
        documentSelector:
        [
            {
                scheme: "file",
                language: "Elyra"
            }
        ]
    };
    client = new LanguageClient("aura", "aura", serverOptions, clientOptions);
    client.start();
}